pragma Singleton

import QtQml 2.12
import QtQuick 2.12

QtObject {
    readonly property color bkColor: "#F7F7F9"
    readonly property color fkColor: "#b2b1b1"

    readonly property color gray: "#b2b1b1"
    readonly property color lightGray: "#dddddd"
    readonly property color light: "#ffffff"
    readonly property color blue: "#2d548b"
    readonly property color red: "red"
    readonly property color dark: "#222222"
    readonly property color transparent: "transparent"

    readonly property color splitLine: "#E8ECEF"
    readonly property color normalblue: "#2DA4FF"
    readonly property color disableblue: "#ABDBFFFF"

    readonly property color normalText: "#252631"
    readonly property color errorText: "#FF3B30"
    readonly property color noticeText: "#98A9BC"
    readonly property color frameLine: "#E4E7ED"
    readonly property color placeHolderText: "#D7DBE0"


    readonly property int smallSize: 10
    readonly property int largeSize: 16


    readonly property real margin: 20
    readonly property real middleMargin: 10
    readonly property real smallMargin: 5
    readonly property real smallmMargin: 2.5
    readonly property int spacing: 10
    readonly property int padding: 5

    // button style.
    readonly property int btnSize: 50
    readonly property int btnMargin: 5
    readonly property int btnImgSize: 24
    readonly property color btnPressedColor: Qt.rgba(0/255, 0/255, 0/255, 0.1)
    readonly property color btnReleasedColor: transparent


    // theme color.
    property color themeColor: "#2DA4FF"

    // font color.
    property color backgroundColor: "#F8FAFB"
    property color backgroundColor_hover: "#F1F1F3"
    property color textColor:       "#252631"
    property color textColor2:      "#4D6074"
    property color textColor3:      "#98A9BC"
    property color textColor_disabled: "#778CA2"
    property color cellSelectColor: Qt.rgba(45/255, 164/255, 255/255, 0.1);

    // line color.
    property color lineColor:   "#E8ECEF"
    property color borderColor: "#DDDDDD"

    // mask color
    property color maskColor: Qt.rgba(0, 0,0, 0.3);

    // font style.
    property string fontFamily: "Microsoft YaHei"
    property int    fontPixel:  12

    readonly property int cellHeadHeight: 22
    readonly property int cellHeadIconHeight: 14
    readonly property int cellHeight: 51
    readonly property int cellIconHeight: 28
    readonly property int cellNameWidth: 300
    readonly property int cellModifyWidth: 160
    readonly property int cellSizeWidth: 100

    readonly property int menuBarHeight: 38
    readonly property int menuBarButtonHeight: 22
    readonly property int tipBarHeight: 22
    readonly property int tipBarButtonHeight: 16
    readonly property color tipBarColor: "#F1F1F3"
    readonly property int statusBarHeight: 44
    readonly property color statusBarColor: Qt.rgba(240/255, 244/255, 245/255, 0.9)

    readonly property int operControlHeight: 30


    readonly property int tabMenuWidth: 160

    readonly property int barHeight: 38
    readonly property int itemHeight: 30
    readonly property int iconHeight: 16
    readonly property int iconWidth: iconHeight
    readonly property int iconHeight2: 14
    readonly property int iconWidth2: iconHeight2
    readonly property int iconHeight3: 11
    readonly property int iconWidth3: iconHeight3
    readonly property color colorWhite: "#FFFFFF"
    readonly property color colorLine: "#484848"
    readonly property color colorLine2: "#D7DBE0"
    readonly property color colorBg: "#333333"
    readonly property color colorBlack: Qt.rgba(255/255, 255/255, 255/255, 1)
    readonly property color colorBlack2: Qt.rgba(255/255, 255/255, 255/255, 0.08)
    readonly property int radius: 8


    // tips.
    property color tipTextColor: "#FFFFFF"
    property color tipBackgroundColor: "#333333"
    property color tipBorderColor: "#484848"
    property real  tipBorderWidth: 1
    property real  tipRadius: 3

    // title view
    property int navTitleHeight: 40
    property int navTitleFontPixel: 13

    // tools.
    property real toolIconWidth: 20
    property real toolIconHeight: 20

    property font font
    font {
        pixelSize: 14
        family: "Microsoft YaHei"
    }

}
