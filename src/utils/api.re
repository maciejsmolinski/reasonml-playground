let getCategories = () =>
  Js.Promise.(
    Fetch.fetch(
      "https://rawgit.com/maciejsmolinski/learnings/master/README.md",
    )
    |> then_(Bs_fetch.Response.text)
    |> then_(text => Data.extractCategories(text) |> resolve)
  );