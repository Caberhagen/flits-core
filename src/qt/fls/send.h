// Copyright (c) 2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SEND_H
#define SEND_H

#include <QWidget>
#include <QPushButton>

#include "qt/fls/pwidget.h"
#include "qt/fls/contactsdropdown.h"
#include "qt/fls/sendmultirow.h"
#include "qt/fls/sendcustomfeedialog.h"
#include "walletmodel.h"
#include "coincontroldialog.h"
#include "zflscontroldialog.h"
#include "qt/fls/tooltipmenu.h"

static const int MAX_SEND_POPUP_ENTRIES = 8;

class FLSGUI;
class ClientModel;
class WalletModel;
class WalletModelTransaction;

namespace Ui {
class send;
class QPushButton;
}

class SendWidget : public PWidget
{
    Q_OBJECT

public:
    explicit SendWidget(FLSGUI* parent);
    ~SendWidget();

    void addEntry();

    void loadClientModel() override;
    void loadWalletModel() override;

Q_SIGNALS:
    /** Signal raised when a URI was entered or dragged to the GUI */
    void receivedURI(const QString& uri);

public Q_SLOTS:
    void onChangeAddressClicked();
    void onChangeCustomFeeClicked();
    void onCoinControlClicked();
    void onOpenUriClicked();
    void onValueChanged();
    void refreshAmounts();
    void changeTheme(bool isLightTheme, QString &theme) override;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private Q_SLOTS:
    void onFLSSelected(bool _isFLS);
    void onSendClicked();
    void onContactsClicked(SendMultiRow* entry);
    void onMenuClicked(SendMultiRow* entry);
    void onAddEntryClicked();
    void clearEntries();
    void clearAll(bool fClearSettings = true);
    void refreshView();
    void onCheckBoxChanged();
    void onContactMultiClicked();
    void onDeleteClicked();
    void onResetCustomOptions(bool fRefreshAmounts);
    void onResetSettings();

private:
    Ui::send *ui;
    QPushButton *coinIcon;
    QPushButton *btnContacts;

    SendCustomFeeDialog* customFeeDialog = nullptr;
    bool isCustomFeeSelected = false;
    bool fDelegationsChecked = false;
    CAmount cachedDelegatedBalance{0};

    int nDisplayUnit;
    QList<SendMultiRow*> entries;
    CoinControlDialog *coinControlDialog = nullptr;

    ContactsDropdown *menuContacts = nullptr;
    TooltipMenu *menu = nullptr;
    // Current focus entry
    SendMultiRow* focusedEntry = nullptr;

    bool isFLS = true;
    void resizeMenu();
    QString recipientsToString(QList<SendCoinsRecipient> recipients);
    SendMultiRow* createEntry();
    bool send(QList<SendCoinsRecipient> recipients);
    bool sendzFLS(QList<SendCoinsRecipient> recipients);
    void setFocusOnLastEntry();
    void showHideCheckBoxDelegations();
    void updateEntryLabels(QList<SendCoinsRecipient> recipients);
    void setCustomFeeSelected(bool isSelected, const CAmount& customFee = DEFAULT_TRANSACTION_FEE);

};

#endif // SEND_H
