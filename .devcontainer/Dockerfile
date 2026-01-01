FROM mcr.microsoft.com/devcontainers/cpp:1-debian-12

ENV PS3DEV=/usr/local/ps3dev
ENV PSL1GHT=${PS3DEV}
ENV PATH=${PATH}:${PS3DEV}/bin:${PS3DEV}/ppu/bin:${PS3DEV}/spu/bin
ENV DEBIAN_FRONTEND=noninteractive

USER root

RUN apt-get update && apt-get install -y \
    git \
    autoconf \
    automake \
    bison \
    flex \
    build-essential \
    ca-certificates \
    gcc \
    libelf-dev \
    make \
    texinfo \
    libncurses-dev \
    patch \
    python-is-python3 \
    subversion \
    wget \
    zlib1g-dev \
    libtool \
    libtool-bin \
    python-dev-is-python3 \
    bzip2 \
    libgmp3-dev \
    libgmp-dev \
    zlib1g-dev \
    pkg-config \
    g++ \
    libssl-dev \
    clang \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p ${PS3DEV} && \
    git clone https://github.com/ps3dev/ps3toolchain.git /tmp/ps3toolchain && \
    cd /tmp/ps3toolchain && \
    chmod +x toolchain.sh && \
    ./toolchain.sh && \
    rm -rf /tmp/ps3toolchain
