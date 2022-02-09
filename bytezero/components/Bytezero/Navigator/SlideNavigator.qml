import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Bytezero.Theme 1.0

TabBar {
    id: tabBar
    background: Rectangle {
        color: Theme.blue
    }
    width: 150
    height: parent.height

    contentItem: ListView {
        model: tabBar.contentModel
        currentIndex: tabBar.currentIndex

        spacing: tabBar.spacing
        orientation: ListView.Vertical
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.AutoFlickIfNeeded
        snapMode: ListView.SnapToItem

        highlightMoveDuration: 0
        highlightRangeMode: ListView.ApplyRange
//        preferredHighlightBegin: 40
//        preferredHighlightEnd: height - 40
    }
}
