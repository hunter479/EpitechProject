FROM node:carbon as final
WORKDIR /app
COPY ./web .
RUN npm install
RUN npm install
RUN npm install -g pm2
CMD pm2-runtime start ecosystem.config.js