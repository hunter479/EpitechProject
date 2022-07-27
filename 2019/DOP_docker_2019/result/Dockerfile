FROM node
WORKDIR /app
COPY . .
RUN npm i npm@latest -g
RUN npm install . --force
RUN npm audit fix --force
EXPOSE 80
CMD node .