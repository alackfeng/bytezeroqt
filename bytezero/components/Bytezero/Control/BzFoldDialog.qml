import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

FileDialog {
    id: foldDialog
    title: qsTr("Select Folds")
    folder: shortcuts.home
    selectExisting: true
    selectFolder: true
    selectMultiple: true

    property var apply: undefined
    signal applyed(var fileUrls, var fileUrl);

    function show(apply = undefined) {
        foldDialog.apply = apply
        foldDialog.open()
    }

    onAccepted: {
        if(foldDialog.apply !== undefined) {
            foldDialog.apply(fileUrls, fileUrl)
        } else {
            foldDialog.applyed(fileUrls, fileUrl)
        }
    }
}
