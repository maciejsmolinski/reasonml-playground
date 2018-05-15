let getCategories: unit => Js.Promise.t(array(Data.category));

let getCategory: string => Js.Promise.t(array(Data.subcategory));