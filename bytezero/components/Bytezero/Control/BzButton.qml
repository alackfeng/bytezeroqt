import QtQuick 2.12
import QtQuick.Controls 2.12
import Bytezero.Theme 1.0


Rectangle {
    id: btn
    color: enabled ? clr_enter : clr_disable
    border.color: "#DDDDDD"
    border.width: 0.5
    radius: 5
    width: 21+button.width+icon.width
    height: 30

    property alias icon_src: icon.source
    property alias icon_width: icon.width
    property alias icon_height: icon.height
    property alias text: button.text

    property color clr_enter: "#FAFAFA"
    property color clr_exit: "#FAFAFA"

    property color clr_click: "#F1F1F1"
    property color clr_release: "#FAFAFA"
    property color clr_disable: "#EEEEEE"

    signal clicked()


    Image {
        id: icon
        width: 14
        height: 14
        fillMode: Image.PreserveAspectFit
        clip: true
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 8
        }
    }

    BzText {
        id: button
        anchors {
            verticalCenter: parent.verticalCenter
            left: icon.right
            leftMargin: 5
            rightMargin: 8
        }

        color: "#252631"
        font.pixelSize: 11
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        acceptedButtons: Qt.LeftButton
        onClicked: {
            parent.clicked()
        }

        onPressed: {
            color = clr_click
        }

        onReleased: {
            color = clr_enter
        }

        onEntered: {
            color = clr_enter
        }

        onExited: {
            color = clr_exit
        }
    }
}

