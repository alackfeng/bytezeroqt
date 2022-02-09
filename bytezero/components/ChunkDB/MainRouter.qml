import QtQuick 2.12
import QtQuick.Controls 2.12
import Bytezero.Navigator 1.0
import ChunkDB 1.0

Item {

    SlideNavigator {
        id: mainNavigator
        TabButton {
            text: qsTr("Home")
            width: implicitWidth
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: { mainLoader.sourceComponent = homePage; }
        }
        TabButton {
            text: qsTr("ChunkDb")
            width: implicitWidth
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: { mainLoader.sourceComponent = dbPage; }
        }
        TabButton {
            text: qsTr("Test")
            width: implicitWidth
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: { mainLoader.sourceComponent = testPage; }
        }
    }

    Loader {
        id: mainLoader
        anchors.top: parent.top
        anchors.left: mainNavigator.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
    Component.onCompleted: {
        mainLoader.sourceComponent = dbPage
        mainNavigator.currentIndex = 1
    }

    Component {
        id: homePage
        HomePage {
        }
    }
    Component {
        id: dbPage
        DBPage {
        }
    }
    Component {
        id: testPage
        TestPage { }
    }
}


