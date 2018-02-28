let url = "https://bucklescript.github.io/docs/en/interop-cheatsheet.html";

[@bs.module]
external fetch : string => Js.Promise.t('a) = "isomorphic-unfetch";

fetch(url)
|> Js.Promise.then_(response => Js.Promise.resolve(response##text()))
|> Js.Promise.then_(data => Js.Promise.resolve(Js.log(data)));