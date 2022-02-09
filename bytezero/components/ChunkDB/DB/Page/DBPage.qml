import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import Bytezero.Theme 1.0
import Bytezero.Control 1.0
import Bytezero.Utils 1.0
import Bytezero.Model 1.0
import "../Panel"
import "../View"

Page {
    title: qsTr("DB Page")

    TabMenu {
        id: tabMenu
        anchors.left: parent.left
        anchors.leftMargin: Theme.spacing
        anchors.right: parent.right
        anchors.rightMargin: Theme.spacing
    }

    OperControl {
        id: operControl
        anchors.top: tabMenu.bottom
        anchors.topMargin: Theme.smallmMargin
        onOperFirst: {
            fileSelector.show(function(fileUrls, fileUrl) {
                console.log("-----------------------fileUrls ", fileUrls)
                console.log("-----------------------fileUrl ", fileUrl)
                dbModel.create(fileUrls)
            })
        }
        onOperSecond: {
            foldSelector.show()
        }


    }

    DbCreateListModel {
        id: dbModel
    }

    StackLayout {
        id: stackLayout
        currentIndex: tabMenu.currentIndex
        anchors.top: operControl.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10

        CreateDBView {
        }
        LoadDBView {
        }

    }

}
