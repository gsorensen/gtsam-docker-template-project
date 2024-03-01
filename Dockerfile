FROM debian:bookworm-slim AS build

# Install the basics
RUN apt-get update && \
    apt-get install build-essential \
                git g++ cmake --assume-yes

# Install Boost 
RUN apt-get install libboost-all-dev --assume-yes

# Install Eigen
#
RUN apt-get install libeigen3-dev --assume-yes

# Install GTSAM
WORKDIR /gtsam-build
RUN git clone https://github.com/borglab/gtsam && \ 
    cd gtsam && git checkout 4.2.0 && \ 
    mkdir build && cd build && cmake .. -DGTSAM_USE_SYSTEM_EIGEN=1 && make install

# Set workdir to /app
WORKDIR /app

# Copy over the files
COPY main.cpp .
COPY CMakeLists.txt .

# This is necessary to get libmetis-gtsam.so to properly link
RUN ldconfig

# Build the C++ project
RUN mkdir build \
    && cd build \
    && cmake .. \
    && make


