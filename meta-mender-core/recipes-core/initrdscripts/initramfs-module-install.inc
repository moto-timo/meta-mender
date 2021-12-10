FILESEXTRAPATHS:prepend_mender-grub := "${THISDIR}/files:"

SRC_URI:append_mender-grub = " file://init-install-efi-mender.sh "

do_install:append_mender-grub() {
    # Overwrite the version of this file provided by upstream
    sed -e 's#[@]MENDER_STORAGE_DEVICE[@]#${MENDER_STORAGE_DEVICE}#' ${WORKDIR}/init-install-efi-mender.sh > init-install-efi-mender-altered.sh
}
