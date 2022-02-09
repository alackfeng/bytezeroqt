import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Bytezero.Model 1.0
import Bytezero.Control 1.0
import Bytezero.Utils 1.0

Item {

    ListView {
        anchors.fill: parent
        model: dbModel
        delegate: RowLayout {
            width: ListView.view.width
            height: 50
            spacing: 5

            Rectangle {
                Layout.preferredWidth: 500
                Layout.preferredHeight: 38
                BzText {
                    width: 500
                    text: qsTr(displayName)
                    elide: Text.ElideMiddle
                }
            }
            Rectangle {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0)
                Layout.preferredWidth: 100
                Layout.preferredHeight: 38
                Text {
                    text: CommJs.bytesToSize(size)
                }
            }
            Rectangle {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0)
                Layout.preferredWidth: 100
                Layout.preferredHeight: 38
                Text {
                    text: CommJs.formatDateString(createTime)
                }
            }
            Rectangle {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0)
                Layout.preferredWidth: 100
                Layout.preferredHeight: 38
                Text {
                    text: CommJs.formatDateString(lastTime)
                }
            }

        }
    }

}
