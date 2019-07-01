let data = [|
  ReactTrello.Lane.t(
    ~id="title1",
    ~label="title1 label",
    ~addCardLink=React.string("title 1 addCardLink"),
    ~cards=[|
      ReactTrello.Card.t(
        ~id="t1 card1",
        ~title="t1 title1",
        ~description="t1 description",
        (),
      ),
      ReactTrello.Card.t(
        ~id="t2 card1",
        ~title="t2 title1",
        ~description="t2 description",
        (),
      ),
    |],
    (),
  ),
  ReactTrello.Lane.t(
    ~id="title2",
    ~label="title2 label",
    ~addCardLink=React.string("title 2 addCardLink"),
    ~cards=[||],
    (),
  ),
|];

[@react.component]
let make = () =>
  <div className="container"> <ReactTrello data={"lanes": data} /> </div>;