FROM svenbcc/expo-android-buildimage as builder
WORKDIR /app
COPY ./mobile .
RUN npm install -g npm
RUN npm install
RUN npm audit fix
RUN mkdir apk && mkdir /apk
RUN apt update && apt install -y python3.7
RUN expo export --dev -p http://127.0.0.1:8000
RUN turtle setup:android --sdk-version 36.0.0
RUN bash entrypoint.sh "build"
CMD bash entrypoint.sh