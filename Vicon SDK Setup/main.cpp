#include <iostream>
#include "DataStreamClient.h"

int main() {
    ViconDataStreamSDK::CPP::Client client;

    // IP and port of the Windows machine running Vicon Tracker
    std::string host = "192.168.10.1:801";

    std::cout << "Connecting to Vicon Tracker at " << host << "..." << std::endl;

    if (client.Connect(host).Result != ViconDataStreamSDK::CPP::Result::Success) {
        std::cerr << "❌ Failed to connect to Vicon Tracker." << std::endl;
        return 1;
    }

    std::cout << "✅ Connected!" << std::endl;

    client.EnableSegmentData();
    client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ClientPull);

    while (true) {
        if (client.GetFrame().Result == ViconDataStreamSDK::CPP::Result::Success) {
            unsigned int subjectCount = client.GetSubjectCount().SubjectCount;

            for (unsigned int i = 0; i < subjectCount; ++i) {
                std::string subjectName = client.GetSubjectName(i).SubjectName;
                unsigned int segmentCount = client.GetSegmentCount(subjectName).SegmentCount;

                for (unsigned int j = 0; j < segmentCount; ++j) {
                    std::string segmentName = client.GetSegmentName(subjectName, j).SegmentName;

                    auto trans = client.GetSegmentGlobalTranslation(subjectName, segmentName);
                    auto rot = client.GetSegmentGlobalRotationEulerXYZ(subjectName, segmentName);

                    std::cout << subjectName << "/" << segmentName << " -> "
                              << "Pos: [" << trans.Translation[0] << ", "
                                           << trans.Translation[1] << ", "
                                           << trans.Translation[2] << "]  "
                              << "Rot: [" << rot.Rotation[0] << "°, "
                                           << rot.Rotation[1] << "°, "
                                           << rot.Rotation[2] << "°]"
                              << std::endl;
                }
            }
        }
    }

    client.Disconnect();
    return 0;
}
