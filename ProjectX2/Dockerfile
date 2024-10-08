# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:22.04

#Default directory
WORKDIR /ProjectX

RUN apt-get update && \
    apt-get install -y --no-install-recommends python3 git curl clang llvm lcov default-jdk zip && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN which clang

RUN curl -L https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 -o /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel

RUN which bazel
RUN bazel --version

# The URL returns 404, probably since CIFuzz is now a commercial product
#RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"
RUN apt-get update && apt-get install make wget libcap-dev

# Install go first
RUN wget https://go.dev/dl/go1.23.1.linux-amd64.tar.gz
RUN tar -C /usr/local -xzf go1.23.1.linux-amd64.tar.gz
ENV PATH="/usr/local/go/bin:${PATH}"
RUN go version

# Install cifuzz
RUN git clone https://github.com/asadhasan73/cifuzz \
    && cd cifuzz \
    && make install

# Install setuptools
RUN apt-get install -y python3-pip
RUN apt-get install python3-setuptools

# Provide your repository link below
RUN git clone https://[<Access token>]@github.com/juskoski/ProjectX2.git

WORKDIR /ProjectX/ProjectX2/ProjectX2

CMD ["sh", "-c", "cifuzz run test:test --use-sandbox=false > fuzzing.log 2>&1 && cat fuzzing.log"]
