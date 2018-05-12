module App = {
  let render: array(string) => unit =
    categories => {
      Document.addReasonApplicationContainer("reason-application");
      ReactDOMRe.renderToElementWithId(
        <Categories data=categories />,
        "reason-application",
      );
    };
  let init: unit => Js.Promise.t(unit) =
    () =>
      Js.Promise.(
        Fetch.fetch(
          "https://rawgit.com/maciejsmolinski/learnings/master/README.md",
        )
        |> then_(Bs_fetch.Response.text)
        |> then_(text => text |> Data.extractCategories |> render |> resolve)
      );
};