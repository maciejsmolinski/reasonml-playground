type configuration = {endpoint: string};

let config = {
  endpoint: "https://rawgit.com/maciejsmolinski/learnings/master/",
};

let getCategories = () => {
  let endpoint = config.endpoint;
  Js.Promise.(
    Fetch.fetch({j|$endpoint/README.md|j})
    |> then_(Bs_fetch.Response.text)
    |> then_(text => Data.extractCategories(text) |> resolve)
  );
};

let getCategory = category => {
  let endpoint = config.endpoint;
  Js.Promise.(
    Fetch.fetch({j|$endpoint/$category.md|j})
    |> then_(Bs_fetch.Response.text)
    |> then_(text => Data.extractSubCategories(text) |> resolve)
  );
};