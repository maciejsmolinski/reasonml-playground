let init = () => {
  Document.addReasonApplicationContainer("reason-application");
  ReactDOMRe.renderToElementWithId(<Application />, "reason-application");
};