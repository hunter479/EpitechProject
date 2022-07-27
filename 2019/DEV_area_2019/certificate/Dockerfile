FROM alpine:latest AS ssl
WORKDIR /app
RUN apk update && apk add --no-cache openssl && rm -rf "/var/cache/apk/*"
COPY ./conf .
RUN sh entrypoint.sh
CMD cp -R /app/certs/ /certs
