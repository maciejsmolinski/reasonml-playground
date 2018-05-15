import * as Main from "./main.bs";
import * as Api from "./utils/api.bs";

Main.init();

Api.getCategory("javascript")
  .then(data => console.log("⌗ Data Received:\n", data))
  .catch(err => console.error("⌗ Error Received:\n", err));
