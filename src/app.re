module App = {
  let render: array(string) => unit =
    categories => {
      Document.addUniqueElement @@ "root";
      ReactDOMRe.renderToElementWithId(
        <Categories data=categories />,
        "root",
      );
    };
  let init: unit => Js.Promise.t(unit) = {
    Document.clear();
    () =>
      Js.Promise.(
        Fetch.fetch(
          "https://rawgit.com/maciejsmolinski/learnings/master/README.md",
        )
        |> then_(Fetch.Response.text)
        |> then_(text => text |> Data.extractCategories |> render |> resolve)
      );
  };
};