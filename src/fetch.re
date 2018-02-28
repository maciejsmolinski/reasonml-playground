[@bs.module]
external fetch : string => Js.Promise.t('a) = "isomorphic-unfetch";

fetch("https://cdn.rawgit.com/maciejsmolinski/learnings/master/README.md")
|> Js.Promise.then_(v => Js.Promise.resolve(v##text()))
|> Js.Promise.then_(v => Js.Promise.resolve(Js.log(v)));