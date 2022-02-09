import QtQuick 2.12
import QtQuick.Controls 2.12
import Bytezero.Navigator 1.0

TabNavigator {
    anchors.left: parent.left
    anchors.leftMargin: Theme.spacing
    anchors.right: parent.right
    anchors.rightMargin: Theme.spacing

    TabButton {
        text: qsTr("Create DB")
        width: implicitWidth
    }
    TabButton {
        text: qsTr("Load DB")
        width: implicitWidth
    }
}
