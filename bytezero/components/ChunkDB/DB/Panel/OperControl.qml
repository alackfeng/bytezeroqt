import QtQuick 2.12
import QtQuick.Controls 2.12
import Bytezero.Theme 1.0
import Bytezero.Control 1.0

Rectangle {
    id: operControl
    color: 'gray'
    height: Theme.operControlHeight
    anchors.left: parent.left
    anchors.leftMargin: Theme.spacing
    anchors.right: parent.right
    anchors.rightMargin: Theme.spacing

    signal operFirst()
    signal operSecond()
    signal operThrid()
    signal operFour()
    signal operFive()

    Row {
        BzButton {
            text: qsTr("Create")
            onClicked: operControl.operFirst()
        }
        BzButton {
            text: qsTr("Test")
            onClicked: operControl.operSecond()
        }
    }


}
