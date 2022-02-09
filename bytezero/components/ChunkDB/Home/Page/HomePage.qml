import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    title: qsTr("Home Page")
    background: Rectangle {
        color: 'red'
    }

    Text {
        id: name
        anchors.centerIn: parent
        text: qsTr("text")
    }
}
