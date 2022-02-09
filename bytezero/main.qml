import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQml 2.12
import Bytezero.Theme 1.0
import Bytezero.Navigator 1.0
import Bytezero.Control 1.0
import ChunkDB 1.0

ApplicationWindow {
    visible: true
    width: Math.min((Screen.desktopAvailableWidth ) / 3 * 2, 980)
    height: Math.min((Screen.desktopAvailableHeight) / 3 * 2, 650)
    minimumWidth: 640
    minimumHeight: 480
    title: bzSdk.title + " " + bzSdk.version

    menuBar: Rectangle {
        height: 30
        color: Theme.gray
    }

    MainRouter {
        anchors.top: menuBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    BzFoldDialog {
        id: foldSelector
    }

    BzFileDialog {
        id: fileSelector
        title: qsTr("Select Rock Files")
        folder: "file:///E:/RockFile/"
        nameFilters: ["Rock Files (*.rock)", "All files (*)"]
    }

}
