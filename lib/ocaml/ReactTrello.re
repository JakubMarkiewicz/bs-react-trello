/*
 draggable	boolean	Makes all cards and lanes draggable. Default: false
 laneDraggable	boolean	Set to false to disable lane dragging. Default: true
 cardDraggable	boolean	Set to false to disable card dragging. Default: true
 collapsibleLanes	boolean	Make the lanes with cards collapsible. Default: false
 editable	boolean	Makes the entire board editable. Allow cards to be added or deleted Default: false
 canAddLanes	boolean	Allows new lanes to be added to the board. Default: false
 addLaneTitle	string	Changes add lane button description. Default: false
 handleDragStart	function	Callback function triggered when card drag is started: handleDragStart(cardId, laneId)
 handleDragEnd	function	Callback function triggered when card drag ends, return false if you want to cancel drop: handleDragEnd(cardId, sourceLaneId, targetLaneId, position, cardDetails)
 handleLaneDragStart	function	Callback function triggered when lane drag is started: handleLaneDragStart(laneId)
 handleLaneDragEnd	function	Callback function triggered when lane drag ends: handleLaneDragEnd(laneId, newPosition, payload)
 cardDragClass	string	CSS class to be applied to Card when being dragged
 laneDragClass	string	CSS class to be applied to Lane when being dragged
 onLaneScroll	function	Called when a lane is scrolled to the end: onLaneScroll(requestedPage, laneId)
 onCardClick	function	Called when a card is clicked: onCardClick(cardId, metadata, laneId)
 onCardAdd	function	Called when a new card is added: onCardAdd(card, laneId)
 onCardDelete	function	Called when a card is deleted: onCardDelete(cardId, laneId)
 onCardMoveAcrossLanes	function	Called when a card is moved across lanes onCardMoveAcrossLanes(fromLaneId, toLaneId, cardId, index)
 onLaneAdd	function	Called when a new lane is added: onLaneAdd(params)
 onLaneDelete	function	Called when a lane is deleted onLaneDelete(laneId)
 onLaneClick	function	Called when a lane is clicked: onLaneClick(laneId). Card clicks are not propagated to lane click event
 addCardLink	node	Pass custom element to replace the Add Card link at the end of the lane (when board is editable)
 newCardTemplate	node	Pass a custom new card template to add new cards to a lane (when board is editable)
 hideCardDeleteIcon	boolean	Disable showing the delete icon to the top right corner of the card (when board is editable)
 laneSortFunction	function	Used to specify the logic to sort cards on a lane: laneSortFunction(card1, card2)
 eventBusHandle	function	This is a special function that providers a publishHook to pass new events to the board. See details in Publish Events section
 onDataChange	function	Called everytime the data changes due to user interaction or event bus: onDataChange(newData)
 style	object	Pass css style props to board container
 customCardLayout	boolean	Boolean to indicate a custom card template will be specified. Add the card component as child to Board
 customLaneHeader	element	Pass custom lane header as react component to modify appearance
 data	object	Actual board data in the form of json
 tagStyle	object	If cards have tags, use this prop to modify their style
 */

module Tag = {
  [@bs.deriving abstract]
  type t = {
    title: string,
    [@bs.optional]
    color: string,
    [@bs.optional]
    bgcolor: string,
  };
};

module Card = {
  [@bs.deriving abstract]
  type t = {
    id: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    index: int,
    [@bs.optional]
    tags: array(Tag.t),
    [@bs.optional]
    description: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    draggable: bool,
  };
};

module Lane = {
  [@bs.deriving abstract]
  type t = {
    id: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    addCardLink: React.element,
    cards: array(Card.t),
  };
};

type data = {. "lanes": array(Lane.t)};

[@bs.obj]
external makePropsTrello:
  (
    ~draggable: bool=?,
    ~laneDraggable: bool=?,
    ~cardDraggable: bool=?,
    ~collapsibleLanes: bool=?,
    ~editable: bool=?,
    ~canAddLanes: bool=?,
    ~addLaneTitle: string=?,
    ~handleDragStart: (string, string) => unit=?,
    ~handleDragEnd: (string, string, string, int, Card.t) => bool=?,
    ~handleLaneDragStart: string => unit=?,
    ~handleLaneDragEnd: (string, string, string, int, Card.t) => unit=?,
    ~cardDragClass: string=?,
    ~laneDragClass: string=?,
    ~onLaneScroll: (int, string) => unit=?,
    ~onCardClick: (string, option(string), string) => unit=?,
    ~onCardAdd: (Card.t, string) => unit=?,
    ~onCardDelete: (string, string) => unit=?,
    ~onCardMoveAcrossLanes: (string, string, string, int) => unit=?,
    ~onLaneAdd: Lane.t => unit=?,
    ~onLaneDelete: string => unit=?,
    ~onLaneClick: string => unit=?,
    ~addCardLink: React.element=?,
    ~newCardTemplate: React.element=?,
    ~hideCardDeleteIcon: React.element=?,
    ~laneSortFunction: (Card.t, Card.t) => unit=?,
    // ~eventBusHandle:         TODO: bind
    // ~onDataChange:           TODO: bind
    ~customCardLayout: bool=?,
    ~customLaneHeader: React.element=?,
    ~data: data,
    ~tagStyle: ReactDOMRe.Style.t=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: Card.t => React.element=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-trello"]
external reactComponent: React.component('a) = "default";

[@react.component]
let make =
    (
      ~draggable: option(bool)=?,
      ~laneDraggable: option(bool)=?,
      ~cardDraggable: option(bool)=?,
      ~collapsibleLanes: option(bool)=?,
      ~editable: option(bool)=?,
      ~canAddLanes: option(bool)=?,
      ~addLaneTitle: option(string)=?,
      ~handleDragStart: option((string, string) => unit)=?,
      ~handleDragEnd: option((string, string, string, int, Card.t) => bool)=?,
      ~handleLaneDragStart: option(string => unit)=?,
      ~handleLaneDragEnd:
         option((string, string, string, int, Card.t) => unit)=?,
      ~cardDragClass: option(string)=?,
      ~laneDragClass: option(string)=?,
      ~onLaneScroll: option((int, string) => unit)=?,
      ~onCardClick: option((string, option(string), string) => unit)=?,
      ~onCardAdd: option((Card.t, string) => unit)=?,
      ~onCardDelete: option((string, string) => unit)=?,
      ~onCardMoveAcrossLanes: option((string, string, string, int) => unit)=?,
      ~onLaneDelete: option(string => unit)=?,
      ~onLaneAdd: option(Lane.t => unit)=?,
      ~onLaneClick: option(string => unit)=?,
      ~addCardLink: option(React.element)=?,
      ~newCardTemplate: option(React.element)=?,
      ~hideCardDeleteIcon: option(React.element)=?,
      ~laneSortFunction: option((Card.t, Card.t) => unit)=?,
      ~customCardLayout: option(bool)=?,
      ~customLaneHeader: option(React.element)=?,
      ~data: data,
      ~tagStyle: option(ReactDOMRe.Style.t)=?,
      ~id: option(string)=?,
      ~className: option(string)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(Card.t => React.element)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsTrello(
      ~draggable?,
      ~laneDraggable?,
      ~cardDraggable?,
      ~collapsibleLanes?,
      ~editable?,
      ~canAddLanes?,
      ~addLaneTitle?,
      ~handleDragStart?,
      ~handleDragEnd?,
      ~handleLaneDragStart?,
      ~handleLaneDragEnd?,
      ~cardDragClass?,
      ~laneDragClass?,
      ~onLaneScroll?,
      ~onCardClick?,
      ~onCardAdd?,
      ~onCardDelete?,
      ~onCardMoveAcrossLanes?,
      ~onLaneAdd?,
      ~onLaneDelete?,
      ~onLaneClick?,
      ~addCardLink?,
      ~newCardTemplate?,
      ~hideCardDeleteIcon?,
      ~laneSortFunction?,
      // ~eventBusHandle?,
      // ~onDataChange?,
      ~customCardLayout?,
      ~customLaneHeader?,
      ~tagStyle?,
      ~data,
      ~id?,
      ~className?,
      ~style?,
      ~children?,
      (),
    ),
  );