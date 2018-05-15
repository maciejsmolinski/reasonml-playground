let getCategories: unit => Js.Promise.t(array(string));

let getCategory: string => Js.Promise.t(array(Data.subcategory));