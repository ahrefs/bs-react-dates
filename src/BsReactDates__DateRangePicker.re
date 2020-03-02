open BsReactDates__Utils;
open Belt;
open MomentRe;

[@bs.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
    ~onDatesChange: Dates.tJs => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~startDateId: string=?,
    ~endDate: Moment.t=?,
    ~endDateId: string=?,
    ~focusedInput: [@bs.string] [ | `startDate | `endDate]=?,
    /* input related props */
    ~startDatePlaceholderText: string=?,
    ~endDatePlaceholderText: string=?,
    ~disabled: [@bs.string] [ | `startDate | `endDate]=?,
    ~required: bool=?,
    ~readOnly: bool=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDates: bool=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: ReasonReact.reactElement=?,
    ~customArrowIcon: ReasonReact.reactElement=?,
    ~customCloseIcon: ReasonReact.reactElement=?,
    ~inputIconPosition: [@bs.string] [ | `before | `after]=?,
    ~noBorder: bool=?,
    ~block: bool=?,
    ~small: bool=?,
    ~regular: bool=?,
    /* calendar presentation and interaction related props */
    ~renderMonth: Moment.t => StrOrNode.t=?,
    ~orientation: [@bs.string] [ | `horizontal | `vertical]=?,
    ~anchorDirection: [@bs.string] [ | `left | `right]=?,
    ~horizontalMargin: int=?,
    ~withPortal: bool=?,
    ~withFullScreenPortal: bool=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~firstDayOfWeek: [@bs.int] [
                       | `Sun
                       | `Mon
                       | `Tue
                       | `Wed
                       | `Thu
                       | `Fri
                       | `Sat
                     ]
                       =?,
    ~numberOfMonths: int=?,
    ~keepOpenOnDateSelect: bool=?,
    ~reopenPickerOnClearDates: bool=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    /* navigation related props */
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: Dates.tJs => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    /* day presentation and interaction related props */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~enableOutsideDays: bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    /* internationalization props */
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  React.element =
  "DateRangePicker";

module Jsx2 = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make =
      (
        ~className=?,
        ~onDatesChange,
        ~onFocusChange,
        ~startDate=?,
        ~startDateId=?,
        ~endDate=?,
        ~endDateId=?,
        ~focusedInput=?,
        ~startDatePlaceholderText=?,
        ~endDatePlaceholderText=?,
        ~disabled=?,
        ~required=?,
        ~readOnly=?,
        ~screenReaderInputMessage=?,
        ~showClearDates=?,
        ~showDefaultInputIcon=?,
        ~customInputIcon=?,
        ~customArrowIcon=?,
        ~customCloseIcon=?,
        ~inputIconPosition=?,
        ~noBorder=?,
        ~block=?,
        ~small=?,
        ~regular=?,
        ~renderMonth=?,
        ~orientation=?,
        ~anchorDirection=?,
        ~horizontalMargin=?,
        ~withPortal=?,
        ~withFullScreenPortal=?,
        ~daySize=?,
        ~isRTL=?,
        ~initialVisibleMonth=?,
        ~firstDayOfWeek=?,
        ~numberOfMonths=?,
        ~keepOpenOnDateSelect=?,
        ~reopenPickerOnClearDates=?,
        ~renderCalendarInfo=?,
        ~hideKeyboardShortcutsPanel=?,
        ~navPrev=?,
        ~navNext=?,
        ~onPrevMonthClick=?,
        ~onNextMonthClick=?,
        ~onClose=?,
        ~transitionDuration=?,
        ~renderCalendarDay=?,
        ~renderDayContents=?,
        ~minimumNights=?,
        ~enableOutsideDays=?,
        ~isDayBlocked=?,
        ~isOutsideRange=?,
        ~isDayHighlighted=?,
        ~displayFormat=?,
        ~monthFormat=?,
        ~weekDayFormat=?,
        ~phrases=?,
        ~dayAriaLabelFormat=?,
        children,
      ) => {
    let handleDatesChange = v => v->Dates.fromJs->onDatesChange;
    let handleFocusChange = v => v->nullableFocusedInputToJs->onFocusChange;
    let handleClose =
      Option.map(
        onClose,
        func => {
          let res = v => v->Dates.fromJs->func;
          res;
        },
      );
    ReasonReactCompat.wrapReactForReasonReact(
      make,
      makeProps(
        ~className?,
        ~onDatesChange=handleDatesChange,
        ~onFocusChange=handleFocusChange,
        ~startDate?,
        ~startDateId?,
        ~endDate?,
        ~endDateId?,
        ~focusedInput?,
        ~startDatePlaceholderText?,
        ~endDatePlaceholderText?,
        ~disabled?,
        ~required?,
        ~readOnly?,
        ~screenReaderInputMessage?,
        ~showClearDates?,
        ~showDefaultInputIcon?,
        ~customInputIcon?,
        ~customArrowIcon?,
        ~customCloseIcon?,
        ~inputIconPosition?,
        ~noBorder?,
        ~block?,
        ~small?,
        ~regular?,
        ~renderMonth?,
        ~orientation?,
        ~anchorDirection?,
        ~horizontalMargin?,
        ~withPortal?,
        ~withFullScreenPortal?,
        ~daySize?,
        ~isRTL?,
        ~initialVisibleMonth?,
        ~firstDayOfWeek?,
        ~numberOfMonths?,
        ~keepOpenOnDateSelect?,
        ~reopenPickerOnClearDates?,
        ~renderCalendarInfo?,
        ~hideKeyboardShortcutsPanel?,
        ~navPrev?,
        ~navNext?,
        ~onPrevMonthClick?,
        ~onNextMonthClick?,
        ~onClose=?handleClose,
        ~transitionDuration?,
        ~renderCalendarDay?,
        ~renderDayContents?,
        ~minimumNights?,
        ~enableOutsideDays?,
        ~isDayBlocked?,
        ~isOutsideRange?,
        ~isDayHighlighted?,
        ~displayFormat=?displayFormat->DisplayFormat.encodeOpt,
        ~monthFormat?,
        ~weekDayFormat?,
        ~phrases?,
        ~dayAriaLabelFormat?,
        (),
      ),
      React.array(children),
    );
  };
};