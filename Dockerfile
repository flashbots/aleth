# stage 1 build
FROM alpine:3.14 AS base-image

RUN apk add --no-cache build-base boost-dev g++ cmake ccache

ADD . /src
RUN mkdir -p /src/build \
 && cd /src/build \
 && cmake .. \
 && cmake --build . \
 && make

FROM alpine:3.14

RUN apk add libstdc++
WORKDIR /src/
COPY --from=base-image /src .