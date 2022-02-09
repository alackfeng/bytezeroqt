import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

FileDialog {
    id: fileDialog
    title: qsTr("Select Files")
    folder: shortcuts.home
    selectExisting: true
    selectFolder: false
    selectMultiple: true
    nameFilters: ["All files (*)"]

    property var apply: undefined
    signal applyed(var fileUrls, var fileUrl);

    function show(apply = undefined) {
        fileDialog.apply = apply
        fileDialog.open()
    }

    onAccepted: {
        console.log("------------------- ", shortcuts.home)
        if(fileDialog.apply !== undefined) {
            fileDialog.apply(fileUrls, fileUrl)
        } else {
            fileDialog.applyed(fileUrls, fileUrl)
        }
    }
}
