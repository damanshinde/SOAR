

>  **Note**: This is *not* a comprehensive guide to setting up acados. For full guide view [acados installation][https://docs.acados.org/installation/index.html]. Additional dependencies may be required depending on your Linux distribution, system architecture, or Python version.  
> This guide assumes **Python 3.8 installed via the deadsnakes PPA**.


##  1. Check Wi-Fi Connectivity
Before proceeding, ensure the drone is connected to Wi-Fi:
```bash
ping google.com
```
If there's no response, troubleshoot Wi-Fi or DNS settings.

## 2. Prepare the Environment
```bash
cd ~/projects
# Ensure this folder exists and has sufficient space
```

##  3. Set Up Python Virtual Environment (Python 3.8)
Install Python 3.8 from deadsnakes:
```bash
sudo apt install python3.8 python3.8-venv python3.8-dev
```
Create and activate a virtual environment:
```bash
python3.8 -m venv ~/py38_env
source ~/py38_env/bin/activate
```

## 4. Clone acados and Navigate
```bash
git clone https://github.com/acados/acados.git ~/projects/acados
cd ~/projects/acados
```

##  5. Install Build Dependencies
You might need the following system packages if they are not already installed:
```bash
sudo apt install \
  build-essential \
  gfortran \
  cmake \
  make \
  pkg-config \
  libblas-dev \
  liblapack-dev \
  libtool \
  autoconf \
  libffi-dev \
  libopenblas-dev \
  python3-pip
```

## 6. Build acados
Inside the `acados` directory:
```bash
mkdir build
cd build
cmake ..
make
```

##  7. Test acados Installation
To verify that acados is working properly:
```bash
cd ~/Downloads/acados/examples/acados_python/getting_started
ls
# Expected output:
# minimal_example_closed_loop.py  minimal_example_sim.py  utils.py
# minimal_example_ocp.py          pendulum_model.py

# Run this basic example:
python3.8 minimal_example_ocp.py
```
If it runs without error, the Python interface to acados is set up correctly.

##  8. Cleanup / Revert
To fully remove everything:
```bash
deactivate
rm -rf ~/projects/acados
rm -rf ~/py38_env
```
