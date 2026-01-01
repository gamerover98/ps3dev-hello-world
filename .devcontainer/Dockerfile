FROM mcr.microsoft.com/devcontainers/cpp:1-debian-12

# ------------------------------------------------------------
# PS3 development environment variables
#
# PS3DEV   : root directory of the PS3 toolchain
# PSL1GHT  : legacy alias used by many build systems
# PATH     : expose ppu/spu toolchains and ps3dev utilities
# ------------------------------------------------------------
ENV PS3DEV=/usr/local/ps3dev
ENV PSL1GHT=${PS3DEV}
ENV PATH=${PATH}:${PS3DEV}/bin:${PS3DEV}/ppu/bin:${PS3DEV}/spu/bin
ENV DEBIAN_FRONTEND=noninteractive

USER root

# ------------------------------------------------------------
# Base build dependencies
#
# These packages are required to:
# - build homebrew software for PlayStation 3
# - compile legacy tools shipped with ps3dev
# - support autotools-based projects (common in PSL1GHT)
# ------------------------------------------------------------
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

# ------------------------------------------------------------
# Prebuilt ps3dev toolchain
#
# This archive contains a legacy but working PS3 toolchain
# (ppu-gcc, spu-gcc, binutils, utilities).
#
# NOTE:
# - Binaries are linked against OpenSSL 1.1
# - Rebuilding the toolchain from source would remove this
#   dependency, but requires significant effort and time
# ------------------------------------------------------------
RUN mkdir -p ${PS3DEV} \
 && cd /usr/local \
 && wget -O ps3dev.tar.gz \
    https://github.com/bucanero/ps3toolchain/releases/download/ubuntu-latest-fad3b5fb/ps3dev-ubuntu-latest-2020-08-31.tar.gz \
 && tar -xzf ps3dev.tar.gz \
 && rm -f ps3dev.tar.gz \
 && mv ps3dev/* ${PS3DEV}/ || true

# ------------------------------------------------------------
# OpenSSL 1.1 compatibility layer
#
# Debian 12 ships OpenSSL 3 only (libcrypto.so.3).
# Many ps3dev binaries are still linked against:
#   libcrypto.so.1.1
#
# Installing libssl1.1 from Debian 11 (bullseye)
# is the safest workaround and avoids ABI breakage.
# ------------------------------------------------------------
RUN wget http://security.debian.org/debian-security/pool/updates/main/o/openssl/libssl1.1_1.1.1w-0+deb11u4_amd64.deb \
 && dpkg -i libssl1.1_1.1.1w-0+deb11u4_amd64.deb \
 && rm -f libssl1.1_1.1.1w-0+deb11u4_amd64.deb

# ------------------------------------------------------------
# Dependencies required to build Python 2.7
#
# Python 2.7 is needed only for legacy scripts in ps3dev
# and some historical build systems.
#
# It should NOT be used for new development.
# ------------------------------------------------------------
RUN apt-get update && apt-get install -y \
    libsqlite3-dev \
    libncurses5-dev \
    libgdbm-dev \
    libbz2-dev \
    libreadline5-dev \
    libdb-dev \
    && rm -rf /var/lib/apt/lists/*

# ------------------------------------------------------------
# Build and install Python 2.7.3 (legacy)
#
# - Installed system-wide under /usr
# - Shared library enabled (--enable-shared)
# - Required for compatibility with old ps3dev scripts
# ------------------------------------------------------------
RUN wget http://www.python.org/ftp/python/2.7.3/Python-2.7.3.tgz \
 && tar -xzf Python-2.7.3.tgz \
 && cd Python-2.7.3 \
 && ./configure --prefix=/usr --enable-shared \
 && make -j$(nproc) \
 && make install \
 && cd / \
 && rm -rf Python-2.7.3 Python-2.7.3.tgz

# ------------------------------------------------------------
# Python alternatives configuration
#
# Some legacy scripts explicitly call "python" and
# expect Python 2.x to be available.
#
# NOTE:
# - Debian 12 does not ship python2.6
# - Fallbacks are guarded with '|| true' to avoid build failure
# ------------------------------------------------------------
RUN update-alternatives --install /usr/bin/python python /usr/bin/python2.6 20 || true \
 && update-alternatives --install /usr/bin/python python /usr/bin/python2.7 10 \
 && update-alternatives --set python /usr/bin/python2.6 || true
