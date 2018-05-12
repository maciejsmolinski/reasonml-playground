module Dom = {
  let clear: unit => unit = [%bs.raw
    {|
    function () {
      typeof document !== 'undefined' && document.body && (document.body.innerHTML = "");
    }
  |}
  ];
  let append: string => unit = [%bs.raw
    {|
      function (content) {
        typeof document !== 'undefined' && document.body && (document.body.innerHTML = document.body.innerHTML + content);
      }
    |}
  ];
  let addUniqueElement: string => unit =
    uniqueId => append({j|<div id="$uniqueId"></div>|j});
};

module Data = {
  let extractCategories: string => array(string) = [%bs.raw
    {|
    function (text) {
      return text.match(/\[.*?\]/ig).map(category => category.slice(1, -1))
    }
  |}
  ];
};

module Category = {
  let component = ReasonReact.statelessComponent("Category");
  let make = (~name, _children) => {
    ...component,
    render: _self =>
      <span className="categories__item tag is-dark">
        (ReasonReact.string(name))
      </span>,
  };
};

module Categories = {
  let component = ReasonReact.statelessComponent("Categories");
  let toCategory = name => <Category name key=name />;
  let make = (~data, _children) => {
    ...component,
    render: _self =>
      <div className="categories">
        (data |> Array.map(toCategory) |> ReasonReact.array)
      </div>,
  };
};

Dom.clear();

let renderApp = arr => {
  Dom.addUniqueElement @@ "root";
  ReactDOMRe.renderToElementWithId(<Categories data=arr />, "root");
};

Js.Promise.(
  Fetch.fetch("https://rawgit.com/maciejsmolinski/learnings/master/README.md")
  |> then_(Fetch.Response.text)
  |> then_(text => text |> Data.extractCategories |> renderApp |> resolve)
);