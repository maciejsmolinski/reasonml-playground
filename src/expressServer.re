module Express = {
  type server;
  type request;
  type next = unit => unit;
  type response = {. [@bs.meth] "send": string => unit};
  type handler = (request, response) => unit;
  type middleware = (request, response, next) => unit;
};

[@bs.module] external express : unit => Express.server = "express";

[@bs.send.pipe: Express.server]
external get : (string, Express.handler) => Express.server = "";

[@bs.send.pipe: Express.server]
external post : (string, Express.handler) => Express.server = "";

[@bs.send.pipe: Express.server]
external use : Express.middleware => Express.server = "";

[@bs.send.pipe: Express.server] external listen : int => Express.server = "";

express()
|> use((_, _, next) => {
     Js.log("Hello from the Middleware");
     next();
   })
|> get("/", (_, res) => res##send("Hello from the GET handler"))
|> post("/", (_, res) => res##send("Hello from the POST handler"))
|> listen(3131);