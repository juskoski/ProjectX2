# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:latest

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

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"

#Provide your repository link below
# TODO: Revoke token after task has been completed
RUN git clone https://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@github.com/juskoski/ProjectX2.git

WORKDIR /ProjectX/software-and-hardware-security-submissions-2024-juskoski/Week2/

CMD ["sh", "-c", "cifuzz run test:test --use-sandbox=false > fuzzing.log 2>&1 && cat fuzzing.log"]
