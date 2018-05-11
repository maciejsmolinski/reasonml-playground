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
  let modules = [|
    <Category name="Compile to JavaScript" />,
    <Category name="Product Development" />,
    <Category name="Haskell" />,
    <Category name="Functional Programming" />,
    <Category name="Finance" />,
    <Category name="Agile" />,
    <Category name="Frontend" />,
    <Category name="JavaScript" />,
    <Category name="Leadership" />,
  |];
  let make = _children => {
    ...component,
    render: _self =>
      <div className="categories"> (modules |> ReasonReact.array) </div>,
  };
};

Dom.clear();

Dom.addUniqueElement @@ "root";

ReactDOMRe.renderToElementWithId(<Categories />, "root");