FROM mcr.microsoft.com/devcontainers/cpp:1-debian-12

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

ENV PS3DEV=/usr/local/ps3dev
ENV PSL1GHT=${PS3DEV}
ENV PATH=${PATH}:${PS3DEV}/bin:${PS3DEV}/ppu/bin:${PS3DEV}/spu/bin
ENV DEBIAN_FRONTEND=noninteractive

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh 

RUN \
  apt-get update && \
  apt-get install -y \
    autoconf \
    bison \
    build-essential \
    ca-certificates \
    flex \
    git \
    libelf-dev \
    libgmp-dev \
    libncurses-dev \
    libssl-dev \
    libtool-bin \
    pkg-config \
    python-dev-is-python3 \
    texinfo \
    wget \
    zlib1g-dev && \
  apt-get clean && \
  rm -rf /var/lib/{apt,dpkg,cache,log}/

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
