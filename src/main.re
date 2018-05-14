let init = () => {
  Document.addReasonApplicationContainer("reason-application");
  ReactDOMRe.renderToElementWithId(<Application />, "reason-application");
  /* ReactDOMServerRe.renderToString(<Application />) |> Js.log;
     ReactDOMServerRe.renderToStaticMarkup(<Application />) |> Js.log; */
  ();
};