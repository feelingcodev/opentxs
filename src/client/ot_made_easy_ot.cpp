/************************************************************
*
*  ot_made_easy_ot.cpp
*
*/

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include "ot_made_easy_ot.hpp"
#include <opentxs/client/ot_otapi_ot.hpp>
#include "ot_utility_ot.hpp"
#include <opentxs/core/OTLog.hpp>

#include <algorithm>

#ifdef ANDROID
#include "opentxs/core/util/android_string.hpp"
#endif

// Returns:
//  True if I have enough numbers, or if there was success getting more
// transaction numbers.
//  False if I didn't have enough numbers, tried to get more, and failed
// somehow.
//

using namespace opentxs;
using namespace std;

OT_MADE_EASY_OT bool MadeEasy::insure_enough_nums(int32_t nNumberNeeded,
                                                  const string& strMyNotaryID,
                                                  const string& strMyNymID)
{
    Utility MsgUtil;
    bool bReturnVal = true;

    // Make sure we have at least one transaction number (to write the
    // cheque...)
    //
    int32_t nTransCount =
        OTAPI_Wrap::GetNym_TransactionNumCount(strMyNotaryID, strMyNymID);

    if (nTransCount < nNumberNeeded) {
        otOut << "insure_enough_nums: I don't have enough "
                 "transaction numbers. Grabbing more now...\n";

        MsgUtil.getTransactionNumbers(strMyNotaryID, strMyNymID, true);

        bool msgWasSent = false;
        if (0 > MadeEasy::retrieve_nym(strMyNotaryID, strMyNymID, msgWasSent,
                                       false)) {
            otOut << "Error: cannot retrieve nym.\n";
            return false;
        }

        // Try again.
        //
        nTransCount =
            OTAPI_Wrap::GetNym_TransactionNumCount(strMyNotaryID, strMyNymID);

        if (nTransCount < nNumberNeeded) {
            otOut
                << "insure_enough_nums: I still don't have enough transaction "
                   "numbers (I have " << nTransCount << ", but I need "
                << nNumberNeeded
                << ".)\n(Tried grabbing some, but failed somehow.)\n";
            return false;
        }
        else {
            bReturnVal = true;
        }
    }

    return bReturnVal;
}

// REGISTER NYM AT SERVER (or download nymfile, if nym already registered.)
//
OT_MADE_EASY_OT string
    MadeEasy::register_nym(const string& NOTARY_ID, const string& NYM_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(REGISTER_NYM, NOTARY_ID, NYM_ID);
    string strResponse = theRequest.SendRequest(theRequest, "REGISTER_NYM");
    int32_t nSuccess = VerifyMessageSuccess(strResponse);

    if (1 == nSuccess) {
        Utility MsgUtil;

        // Use the getRequestNumber command, thus insuring that the request
        // number is
        // in sync.
        //
        if (1 != MsgUtil.getRequestNumber(NOTARY_ID, NYM_ID)) {
            otOut << "\n Succeeded in register_nym, but strange: "
                     "then failed calling getRequestNumber, to sync the "
                     "request number for the first time.\n";
            return "";
        }
    }
    else {
        // maybe an invalid server ID or the server contract isn't available (do
        // AddServerContract(..) first)
        otOut << "Failed to register_nym.\n";
        return "";
    }

    return strResponse;
}

// RETRIEVE NYM INTERMEDIARY FILES

OT_MADE_EASY_OT int32_t
    MadeEasy::retrieve_nym(const string& strNotaryID, const string& strMyNymID,
                           bool& bWasMsgSent, bool bForceDownload)
{

    Utility MsgUtil;

    if (1 != MsgUtil.getRequestNumber(strNotaryID, strMyNymID)) {
        otOut << "\n Failed calling getRequestNumber, to sync the "
                 "request number. (Finished.)\n";
        return -1;
    }
    else // If it returns 1, we know for sure that the request number is in
           // sync.
    {
        otOut << "\n\n SUCCESS syncronizing the request number.\n";
    }

    int32_t nGetAndProcessNymbox = MsgUtil.getAndProcessNymbox_4(
        strNotaryID, strMyNymID, bWasMsgSent, bForceDownload);

    return nGetAndProcessNymbox;
}

// CHECK USER (download a public key)
//
OT_MADE_EASY_OT string MadeEasy::check_nym(const string& NOTARY_ID,
                                           const string& NYM_ID,
                                           const string& TARGET_NYM_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(CHECK_NYM, NOTARY_ID, NYM_ID, TARGET_NYM_ID);
    string strResponse = theRequest.SendRequest(theRequest, "CHECK_NYM");

    return strResponse;
}

//  CREATE NYM (pseudonym)
//  returns new Nym ID
//
OT_MADE_EASY_OT string MadeEasy::create_nym(int32_t nKeybits,
                                            const string& strNymIDSource,
                                            const string& strAltLocation)
{
    string strLocation = "OT_ME_create_nym";

    string strNymID = OTAPI_Wrap::CreateNym(
        nKeybits, strNymIDSource, strAltLocation); // returns new Nym ID;

    if (!VerifyStringVal(strNymID)) {
        otOut << strLocation
              << ": Failed in OT_API_CreateNym(keybits == " << nKeybits
              << ")\n";
    }

    return strNymID;
}

//  ISSUE ASSET TYPE
//
OT_MADE_EASY_OT string MadeEasy::issue_asset_type(const string& NOTARY_ID,
                                                  const string& NYM_ID,
                                                  const string& THE_CONTRACT)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(ISSUE_ASSET_TYPE, NOTARY_ID, NYM_ID, THE_CONTRACT);
    string strResponse = theRequest.SendRequest(theRequest, "ISSUE_ASSET_TYPE");

    return strResponse;
}

//  ISSUE BASKET CURRENCY
//
OT_MADE_EASY_OT string MadeEasy::issue_basket_currency(const string& NOTARY_ID,
                                                       const string& NYM_ID,
                                                       const string& THE_BASKET)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(ISSUE_BASKET, NOTARY_ID, NYM_ID, THE_BASKET);
    string strResponse = theRequest.SendRequest(theRequest, "ISSUE_BASKET");

    return strResponse;
}

//  EXCHANGE BASKET CURRENCY
//
OT_MADE_EASY_OT string MadeEasy::exchange_basket_currency(
    const string& NOTARY_ID, const string& NYM_ID, const string& ASSET_TYPE,
    const string& THE_BASKET, const string& ACCT_ID, bool IN_OR_OUT)
{
    OTAPI_Func ot_Msg;

    int32_t nTransNumsNeeded =
        (OTAPI_Wrap::Basket_GetMemberCount(THE_BASKET) + 1);

    OTAPI_Func theRequest(EXCHANGE_BASKET, NOTARY_ID, NYM_ID, ASSET_TYPE,
                          THE_BASKET, ACCT_ID, IN_OR_OUT, nTransNumsNeeded);
    string strResponse =
        theRequest.SendTransaction(theRequest, "EXCHANGE_BASKET");

    return strResponse;
}

//  RETRIEVE CONTRACT
//
OT_MADE_EASY_OT string MadeEasy::retrieve_contract(const string& NOTARY_ID,
                                                   const string& NYM_ID,
                                                   const string& CONTRACT_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_CONTRACT, NOTARY_ID, NYM_ID, CONTRACT_ID);
    string strResponse = theRequest.SendRequest(theRequest, "GET_CONTRACT");

    return strResponse;
}

//  LOAD OR RETRIEVE CONTRACT
//
OT_MADE_EASY_OT string
    MadeEasy::load_or_retrieve_contract(const string& NOTARY_ID,
                                        const string& NYM_ID,
                                        const string& CONTRACT_ID)
{
    OTAPI_Func ot_Msg;

    string strContract = OTAPI_Wrap::LoadAssetContract(CONTRACT_ID);

    if (!VerifyStringVal(strContract)) {
        string strResponse = retrieve_contract(NOTARY_ID, NYM_ID, CONTRACT_ID);

        if (1 == VerifyMessageSuccess(strResponse)) {
            strContract = OTAPI_Wrap::LoadAssetContract(CONTRACT_ID);
        }
    }

    return strContract; // might be null.
}

//  CREATE ASSET ACCOUNT
//
OT_MADE_EASY_OT string
    MadeEasy::create_asset_acct(const string& NOTARY_ID, const string& NYM_ID,
                                const string& INSTRUMENT_DEFINITION_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(CREATE_ASSET_ACCT, NOTARY_ID, NYM_ID,
                          INSTRUMENT_DEFINITION_ID);
    string strResponse =
        theRequest.SendRequest(theRequest, "CREATE_ASSET_ACCT");

    return strResponse;
}

OT_MADE_EASY_OT string MadeEasy::stat_asset_account(const string& ACCOUNT_ID)
{
    string strNymID = OTAPI_Wrap::GetAccountWallet_NymID(ACCOUNT_ID);
    if (!VerifyStringVal(strNymID)) {
        otOut << "\nstat_asset_account: Cannot find account wallet for: "
              << ACCOUNT_ID << "\n";
        return "";
    }

    string strInstrumentDefinitionID =
        OTAPI_Wrap::GetAccountWallet_InstrumentDefinitionID(ACCOUNT_ID);
    if (!VerifyStringVal(strInstrumentDefinitionID)) {
        otOut << "\nstat_asset_account: Cannot cannot determine instrument "
                 "definition for: " << ACCOUNT_ID << "\n";
        return "";
    }

    string strName = OTAPI_Wrap::GetAccountWallet_Name(ACCOUNT_ID);
    string strNotaryID = OTAPI_Wrap::GetAccountWallet_NotaryID(ACCOUNT_ID);
    int64_t lBalance = OTAPI_Wrap::GetAccountWallet_Balance(ACCOUNT_ID);
    string strAssetTypeName =
        OTAPI_Wrap::GetAssetType_Name(strInstrumentDefinitionID);
    string strNymName = OTAPI_Wrap::GetNym_Name(strNymID);
    string strServerName = OTAPI_Wrap::GetServer_Name(strNotaryID);

    return "   Balance: " +
           OTAPI_Wrap::FormatAmount(strInstrumentDefinitionID, lBalance) +
           "   (" + strName + ")\nAccount ID: " + ACCOUNT_ID + " ( " + strName +
           " )\nAsset Type: " + strInstrumentDefinitionID + " ( " +
           strAssetTypeName + " )\nOwner Nym : " + strNymID + " ( " +
           strNymName + " )\nServer    : " + strNotaryID + " ( " +
           strServerName + " )";
}

// DOWNLOAD ACCOUNT FILES  (account balance, inbox, outbox, etc)
//

// returns true/false
OT_MADE_EASY_OT bool MadeEasy::retrieve_account(
    const string& NOTARY_ID, const string& NYM_ID, const string& ACCOUNT_ID,
    bool bForceDownload) // bForceDownload=false
{
    Utility MsgUtil;

    bool bResponse = MsgUtil.getIntermediaryFiles(NOTARY_ID, NYM_ID, ACCOUNT_ID,
                                                  bForceDownload);
    return bResponse;
}

// SEND TRANSFER  -- TRANSACTION

OT_MADE_EASY_OT string
    MadeEasy::send_transfer(const string& NOTARY_ID, const string& NYM_ID,
                            const string& ACCT_FROM, const string& ACCT_TO,
                            int64_t AMOUNT, const string& NOTE)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(SEND_TRANSFER, NOTARY_ID, NYM_ID, ACCT_FROM, ACCT_TO,
                          AMOUNT, NOTE);
    string strResponse =
        theRequest.SendTransaction(theRequest, "SEND_TRANSFER");

    return strResponse;
}

// PROCESS INBOX  -- TRANSACTION

OT_MADE_EASY_OT string MadeEasy::process_inbox(const string& NOTARY_ID,
                                               const string& NYM_ID,
                                               const string& ACCOUNT_ID,
                                               const string& RESPONSE_LEDGER)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(PROCESS_INBOX, NOTARY_ID, NYM_ID, ACCOUNT_ID,
                          RESPONSE_LEDGER);
    string strResponse =
        theRequest.SendTransaction(theRequest, "PROCESS_INBOX");

    return strResponse;
}

// load_public_key():
//
// Load a public key from local storage, and return it (or null).
//
OT_MADE_EASY_OT string
    MadeEasy::load_public_encryption_key(const string& NYM_ID) // from local
                                                               // storage.
{
    OTAPI_Func ot_Msg;

    otOut << "\nload_public_encryption_key: Trying to load public "
             "key, assuming Nym isn't in the local wallet...\n";

    string strPubkey = OTAPI_Wrap::LoadPubkey_Encryption(
        NYM_ID); // This version is for "other people";

    if (!VerifyStringVal(strPubkey)) {
        otOut << "\nload_public_encryption_key: Didn't find the Nym (" << NYM_ID
              << ") as an 'other' user, so next, checking to see if there's "
                 "a pubkey available for one of the local private Nyms...\n";
        strPubkey = OTAPI_Wrap::LoadUserPubkey_Encryption(
            NYM_ID); // This version is for "the user sitting at the machine.";

        if (!VerifyStringVal(strPubkey)) {
            otOut << "\nload_public_encryption_key: Didn't find "
                     "him as a local Nym either... returning nullptr.\n";
        }
    }
    return strPubkey; // might be null.;
}

// load_public_key():
//
// Load a public key from local storage, and return it (or null).
//
OT_MADE_EASY_OT string
    MadeEasy::load_public_signing_key(const string& NYM_ID) // from local
                                                            // storage.
{
    OTAPI_Func ot_Msg;

    string strPubkey = OTAPI_Wrap::LoadPubkey_Signing(
        NYM_ID); // This version is for "other people";

    if (!VerifyStringVal(strPubkey)) {
        strPubkey = OTAPI_Wrap::LoadUserPubkey_Signing(
            NYM_ID); // This version is for "the user sitting at the machine.";
    }
    return strPubkey; // might be null.;
}

//
// load_or_retrieve_pubkey()
//
// Load TARGET_NYM_ID from local storage.
// If not there, then retrieve TARGET_NYM_ID from server,
// using NYM_ID to send check_nym request. Then re-load
// and return. (Might still return null.)
//
OT_MADE_EASY_OT string
    MadeEasy::load_or_retrieve_encrypt_key(const string& NOTARY_ID,
                                           const string& NYM_ID,
                                           const string& TARGET_NYM_ID)
{
    OTAPI_Func ot_Msg;

    string strPubkey = load_public_encryption_key(TARGET_NYM_ID);

    if (!VerifyStringVal(strPubkey)) {
        string strResponse = check_nym(NOTARY_ID, NYM_ID, TARGET_NYM_ID);

        if (1 == VerifyMessageSuccess(strResponse)) {
            strPubkey = load_public_encryption_key(TARGET_NYM_ID);
        }
    }
    return strPubkey; // might be null.
}

OT_MADE_EASY_OT string
    MadeEasy::load_or_retrieve_signing_key(const string& NOTARY_ID,
                                           const string& NYM_ID,
                                           const string& TARGET_NYM_ID)
{
    OTAPI_Func ot_Msg;

    string strPubkey = load_public_signing_key(TARGET_NYM_ID);

    if (!VerifyStringVal(strPubkey)) {
        string strResponse = check_nym(NOTARY_ID, NYM_ID, TARGET_NYM_ID);

        if (1 == VerifyMessageSuccess(strResponse)) {
            strPubkey = load_public_signing_key(TARGET_NYM_ID);
        }
    }
    return strPubkey; // might be null.
}

// SEND USER MESSAGE  (requires recipient public key)
//
OT_MADE_EASY_OT string
    MadeEasy::send_user_msg_pubkey(const string& NOTARY_ID,
                                   const string& NYM_ID,
                                   const string& RECIPIENT_NYM_ID,
                                   const string& RECIPIENT_PUBKEY,
                                   const string& THE_MESSAGE)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(SEND_USER_MESSAGE, NOTARY_ID, NYM_ID,
                          RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_MESSAGE);
    string strResponse =
        theRequest.SendRequest(theRequest, "SEND_USER_MESSAGE");

    return strResponse;
}

// SEND USER INSTRUMENT  (requires recipient public key)
//
OT_MADE_EASY_OT string
    MadeEasy::send_user_pmnt_pubkey(const string& NOTARY_ID,
                                    const string& NYM_ID,
                                    const string& RECIPIENT_NYM_ID,
                                    const string& RECIPIENT_PUBKEY,
                                    const string& THE_INSTRUMENT)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(SEND_USER_INSTRUMENT, NOTARY_ID, NYM_ID,
                          RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_INSTRUMENT);
    string strResponse =
        theRequest.SendRequest(theRequest, "SEND_USER_INSTRUMENT");

    return strResponse;
}

// SEND USER CASH  (requires recipient public key)
//
OT_MADE_EASY_OT string MadeEasy::send_user_cash_pubkey(
    const string& NOTARY_ID, const string& NYM_ID,
    const string& RECIPIENT_NYM_ID, const string& RECIPIENT_PUBKEY,
    const string& THE_INSTRUMENT, const string& INSTRUMENT_FOR_SENDER)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(SEND_USER_INSTRUMENT, NOTARY_ID, NYM_ID,
                          RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_INSTRUMENT,
                          INSTRUMENT_FOR_SENDER);
    string strResponse =
        theRequest.SendRequest(theRequest, "SEND_USER_INSTRUMENT");

    return strResponse;
}

// SEND USER MESSAGE  (only requires recipient's ID, and retrieves pubkey
// automatically)
//
OT_MADE_EASY_OT string MadeEasy::send_user_msg(const string& NOTARY_ID,
                                               const string& NYM_ID,
                                               const string& RECIPIENT_NYM_ID,
                                               const string& THE_MESSAGE)
{
    OTAPI_Func ot_Msg;

    string strRecipientPubkey =
        load_or_retrieve_encrypt_key(NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID);

    if (!VerifyStringVal(strRecipientPubkey)) {
        otOut << "OT_ME_send_user_msg: Unable to load or retrieve "
                 "public encryption key for recipient: " << RECIPIENT_NYM_ID
              << "\n";
        return strRecipientPubkey; // basically this means "return null".
    }

    string strResponse = send_user_msg_pubkey(
        NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID, strRecipientPubkey, THE_MESSAGE);

    return strResponse;
}

// SEND USER PAYMENT  (only requires recipient's ID, and retrieves pubkey
// automatically)
//
OT_MADE_EASY_OT string
    MadeEasy::send_user_payment(const string& NOTARY_ID, const string& NYM_ID,
                                const string& RECIPIENT_NYM_ID,
                                const string& THE_PAYMENT)
{
    OTAPI_Func ot_Msg;

    string strRecipientPubkey =
        load_or_retrieve_encrypt_key(NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID);

    if (!VerifyStringVal(strRecipientPubkey)) {
        otOut << "OT_ME_send_user_payment: Unable to load or "
                 "retrieve public encryption key for recipient: "
              << RECIPIENT_NYM_ID << "\n";
        return strRecipientPubkey; // basically this means "return null".
    }

    string strResponse = send_user_pmnt_pubkey(
        NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID, strRecipientPubkey, THE_PAYMENT);

    return strResponse;
}

// SEND USER CASH  (only requires recipient's ID, and retrieves pubkey
// automatically)
//
OT_MADE_EASY_OT string MadeEasy::send_user_cash(const string& NOTARY_ID,
                                                const string& NYM_ID,
                                                const string& RECIPIENT_NYM_ID,
                                                const string& THE_PAYMENT,
                                                const string& SENDERS_COPY)
{
    OTAPI_Func ot_Msg;

    string strRecipientPubkey =
        load_or_retrieve_encrypt_key(NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID);

    if (!VerifyStringVal(strRecipientPubkey)) {
        otOut << "OT_ME_send_user_payment: Unable to load or "
                 "retrieve public encryption key for recipient: "
              << RECIPIENT_NYM_ID << "\n";
        return strRecipientPubkey; // basically this means "return null".
    }

    string strResponse =
        send_user_cash_pubkey(NOTARY_ID, NYM_ID, RECIPIENT_NYM_ID,
                              strRecipientPubkey, THE_PAYMENT, SENDERS_COPY);

    return strResponse;
}

// GET PAYMENT INSTRUMENT (from payments inbox, by index.)
//
OT_MADE_EASY_OT string MadeEasy::get_payment_instrument(
    const string& NOTARY_ID, const string& NYM_ID, int32_t nIndex,
    const string& PRELOADED_INBOX) // PRELOADED_INBOX is optional.
{
    string strInstrument;
    string strInbox =
        VerifyStringVal(PRELOADED_INBOX)
            ? PRELOADED_INBOX
            : OTAPI_Wrap::LoadPaymentInbox(
                  NOTARY_ID, NYM_ID); // Returns nullptr, or an inbox.

    if (!VerifyStringVal(strInbox)) {
        otWarn << "\n\n get_payment_instrument:  "
                  "OT_API_LoadPaymentInbox Failed. (Probably just "
                  "doesn't exist yet.)\n\n";
        return "";
    }

    int32_t nCount =
        OTAPI_Wrap::Ledger_GetCount(NOTARY_ID, NYM_ID, NYM_ID, strInbox);
    if (0 > nCount) {
        otOut
            << "Unable to retrieve size of payments inbox ledger. (Failure.)\n";
        return "";
    }
    if (nIndex > (nCount - 1)) {
        otOut << "Index " << nIndex
              << " out of bounds. (The last index is: " << (nCount - 1)
              << ". The first is 0.)\n";
        return "";
    }

    strInstrument = OTAPI_Wrap::Ledger_GetInstrument(NOTARY_ID, NYM_ID, NYM_ID,
                                                     strInbox, nIndex);
    if (!VerifyStringVal(strInstrument)) {
        otOut << "Failed trying to get payment instrument from payments box.\n";
        return "";
    }

    return strInstrument;
}

// GET BOX RECEIPT
// Note: nBoxType is 0 for Nymbox, 1 for Inbox, and 2 for Outbox.
// Also, if nBoxType is 0 (nymbox) then you have to pass the NymID in the
// ACCT_ID
// argument, as well as the NYM_ID argument (you have to pass it twice...)
// Otherwise for inbox/outbox, pass the actual ACCT_ID there as normal.
//
OT_MADE_EASY_OT string
    MadeEasy::get_box_receipt(const string& NOTARY_ID, const string& NYM_ID,
                              const string& ACCT_ID, int32_t nBoxType,
                              const string& STR_TRANS_NUM)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_BOX_RECEIPT, NOTARY_ID, NYM_ID, ACCT_ID,
                          to_string(nBoxType), STR_TRANS_NUM);
    string strResponse = theRequest.SendRequest(theRequest, "GET_BOX_RECEIPT");

    return strResponse;
}

// DOWNLOAD PUBLIC MINT
//
OT_MADE_EASY_OT string
    MadeEasy::retrieve_mint(const string& NOTARY_ID, const string& NYM_ID,
                            const string& INSTRUMENT_DEFINITION_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_MINT, NOTARY_ID, NYM_ID,
                          INSTRUMENT_DEFINITION_ID);
    string strResponse = theRequest.SendRequest(theRequest, "GET_MINT");

    return strResponse;
}

// LOAD MINT (from local storage)
//
// To load a mint withOUT retrieving it from server, call:
//
// var strMint = OTAPI_Wrap::LoadMint(NOTARY_ID, INSTRUMENT_DEFINITION_ID);
// It returns the mint, or null.

// LOAD MINT (from local storage).
// Also, if necessary, RETRIEVE it from the server first.
//
// Returns the mint, or null.

OT_MADE_EASY_OT string
    MadeEasy::load_or_retrieve_mint(const string& NOTARY_ID,
                                    const string& NYM_ID,
                                    const string& INSTRUMENT_DEFINITION_ID)
{
    string response = check_nym(NOTARY_ID, NYM_ID, NYM_ID);
    if (1 != VerifyMessageSuccess(response)) {
        otOut << "OT_ME_load_or_retrieve_mint: Cannot verify nym for IDs: \n";
        otOut << "  Server ID: " << NOTARY_ID << "\n";
        otOut << "     Nym ID: " << NYM_ID << "\n";
        otOut << "   Instrument Definition Id: " << INSTRUMENT_DEFINITION_ID
              << "\n";
        return "";
    }

    // HERE, WE MAKE SURE WE HAVE THE PROPER MINT...
    //
    // Download the public mintfile if it's not there, or if it's expired.
    // Also load it up into memory as a string (just to make sure it works.)

    // expired or missing.
    if (!OTAPI_Wrap::Mint_IsStillGood(NOTARY_ID, INSTRUMENT_DEFINITION_ID)) {
        otWarn << "OT_ME_load_or_retrieve_mint: Mint file is "
                  "missing or expired. Downloading from "
                  "server...\n";

        response = retrieve_mint(NOTARY_ID, NYM_ID, INSTRUMENT_DEFINITION_ID);

        if (1 != VerifyMessageSuccess(response)) {
            otOut << "OT_ME_load_or_retrieve_mint: Unable to "
                     "retrieve mint for IDs: \n";
            otOut << "  Server ID: " << NOTARY_ID << "\n";
            otOut << "     Nym ID: " << NYM_ID << "\n";
            otOut << "   Instrument Definition Id: " << INSTRUMENT_DEFINITION_ID
                  << "\n";
            return "";
        }

        if (!OTAPI_Wrap::Mint_IsStillGood(NOTARY_ID,
                                          INSTRUMENT_DEFINITION_ID)) {
            otOut << "OT_ME_load_or_retrieve_mint: Retrieved "
                     "mint, but still 'not good' for IDs: \n";
            otOut << "  Server ID: " << NOTARY_ID << "\n";
            otOut << "     Nym ID: " << NYM_ID << "\n";
            otOut << "   Instrument Definition Id: " << INSTRUMENT_DEFINITION_ID
                  << "\n";
            return "";
        }
    }
    // else // current mint IS available already on local storage (and not
    // expired.)

    // By this point, the mint is definitely good, whether we had to download it
    // or not.
    // It's here, and it's NOT expired. (Or we would have returned already.)

    string strMint = OTAPI_Wrap::LoadMint(NOTARY_ID, INSTRUMENT_DEFINITION_ID);
    if (!VerifyStringVal(strMint)) {
        otOut << "OT_ME_load_or_retrieve_mint: Unable to load mint for IDs: \n";
        otOut << "  Server ID: " << NOTARY_ID << "\n";
        otOut << "     Nym ID: " << NYM_ID << "\n";
        otOut << "   Instrument Definition Id: " << INSTRUMENT_DEFINITION_ID
              << "\n";
    }

    return strMint;
}

// QUERY ASSET TYPES
//
// See if some instrument definitions are issued on the server.
//
OT_MADE_EASY_OT string MadeEasy::query_asset_types(const string& NOTARY_ID,
                                                   const string& NYM_ID,
                                                   const string& ENCODED_MAP)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(QUERY_ASSET_TYPES, NOTARY_ID, NYM_ID, ENCODED_MAP);
    string strResponse =
        theRequest.SendRequest(theRequest, "QUERY_ASSET_TYPES");

    return strResponse;
}

// CREATE MARKET OFFER  -- TRANSACTION

OT_MADE_EASY_OT string MadeEasy::create_market_offer(
    const string& ASSET_ACCT_ID, const string& CURRENCY_ACCT_ID,
    const string& scale, const string& minIncrement, const string& quantity,
    const string& price, bool bSelling, const string& strLifespanInSeconds,
    const string& strStopSign, const string& strActivationPrice)
{
    OTAPI_Func ot_Msg;

    string strNotaryID = OTAPI_Wrap::GetAccountWallet_NotaryID(ASSET_ACCT_ID);
    string strUserID = OTAPI_Wrap::GetAccountWallet_NymID(ASSET_ACCT_ID);

    OTAPI_Func theRequest(CREATE_MARKET_OFFER, strNotaryID, strUserID,
                          ASSET_ACCT_ID, CURRENCY_ACCT_ID, scale, minIncrement,
                          quantity, price, bSelling);

    // Cannot have more than 10 parameters in a function call, in this script.
    // So I am forced to set the final parameters by hand, before sending the
    // transaction:
    //
    if (VerifyStringVal(strLifespanInSeconds)) {
        theRequest.tData =
            OTTimeGetTimeFromSeconds(stoll(strLifespanInSeconds));
    }

    if (VerifyStringVal(strStopSign)) {
        theRequest.strData5 = strStopSign;
    }

    if (VerifyStringVal(strActivationPrice)) {
        theRequest.lData = stoll(strActivationPrice);
    }

    string strResponse =
        theRequest.SendTransaction(theRequest, "CREATE_MARKET_OFFER");

    return strResponse;
}

// KILL MARKET OFFER  -- TRANSACTION
//
OT_MADE_EASY_OT string MadeEasy::kill_market_offer(const string& NOTARY_ID,
                                                   const string& NYM_ID,
                                                   const string& ASSET_ACCT_ID,
                                                   const string& STR_TRANS_NUM)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(KILL_MARKET_OFFER, NOTARY_ID, NYM_ID, ASSET_ACCT_ID,
                          STR_TRANS_NUM);
    string strResponse =
        theRequest.SendTransaction(theRequest, "KILL_MARKET_OFFER");

    return strResponse;
}

// KILL PAYMENT PLAN (an active one that's already running) -- TRANSACTION
//
OT_MADE_EASY_OT string MadeEasy::kill_payment_plan(const string& NOTARY_ID,
                                                   const string& NYM_ID,
                                                   const string& ACCT_ID,
                                                   const string& STR_TRANS_NUM)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(KILL_PAYMENT_PLAN, NOTARY_ID, NYM_ID, ACCT_ID,
                          STR_TRANS_NUM);
    string strResponse =
        theRequest.SendTransaction(theRequest, "KILL_PAYMENT_PLAN");

    return strResponse;
}

// ACTIVATE SMART CONTRACT  -- TRANSACTION
//
OT_MADE_EASY_OT string MadeEasy::activate_smart_contract(
    const string& NOTARY_ID, const string& NYM_ID, const string& ACCT_ID,
    const string& AGENT_NAME, const string& THE_SMART_CONTRACT)
{
    OTAPI_Func ot_Msg;

    //  int32_t OTAPI_Wrap::activateSmartContract(NOTARY_ID, NYM_ID,
    // THE_SMART_CONTRACT)

    OTAPI_Func theRequest(ACTIVATE_SMART_CONTRACT, NOTARY_ID, NYM_ID, ACCT_ID,
                          AGENT_NAME, THE_SMART_CONTRACT);
    string strResponse =
        theRequest.SendTransaction(theRequest, "ACTIVATE_SMART_CONTRACT");

    return strResponse;
}

// DEPOSIT PAYMENT PLAN  -- TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::deposit_payment_plan(const string& NOTARY_ID,
                                   const string& NYM_ID,
                                   const string& THE_PAYMENT_PLAN)
{
    OTAPI_Func ot_Msg;

    // NOTE: We have to include the account ID as well. Even though the API call
    // itself
    // doesn't need it (it retrieves it from the plan itself, as we are about to
    // do here)
    // we still have to provide the accountID for OTAPI_Func, which uses it to
    // grab the
    // intermediary files, as part of its automated sync duties. (FYI.)
    //
    string strSenderAcctID =
        OTAPI_Wrap::Instrmnt_GetSenderAcctID(THE_PAYMENT_PLAN);

    //  int32_t OTAPI_Wrap::depositPaymentPlan(NOTARY_ID, NYM_ID,
    // THE_PAYMENT_PLAN)
    OTAPI_Func theRequest(DEPOSIT_PAYMENT_PLAN, NOTARY_ID, NYM_ID,
                          strSenderAcctID, THE_PAYMENT_PLAN);
    string strResponse =
        theRequest.SendTransaction(theRequest, "DEPOSIT_PAYMENT_PLAN");
    return strResponse;
}

// CANCEL PAYMENT PLAN (an inactive one that hasn't been activated yet) --
// TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::cancel_payment_plan(const string& NOTARY_ID, const string& NYM_ID,
                                  const string& THE_PAYMENT_PLAN)
{
    OTAPI_Func ot_Msg;

    // NOTE: We have to include the account ID as well. Even though the API call
    // itself
    // doesn't need it (it retrieves it from the plan itself, as we are about to
    // do here)
    // we still have to provide the accountID for OTAPI_Func, which uses it to
    // grab the
    // intermediary files, as part of its automated sync duties. (FYI.)
    //
    string strRecipientAcctID =
        OTAPI_Wrap::Instrmnt_GetRecipientAcctID(THE_PAYMENT_PLAN);

    //  otOut << "\n\n DEBUGGING: NYM_ID: "+NYM_ID+"
    // strRecipientAcctID: "+strRecipientAcctID+" \n\n")

    // NOTE: Normally the SENDER (PAYER) is the one who deposits a payment plan.
    // But
    // in this case, the RECIPIENT (PAYEE) deposits it -- which means "Please
    // cancel this plan."
    // It SHOULD fail, since it's only been signed by the recipient, and not the
    // sender.
    // And that failure is what burns the transaction number on the plan, so
    // that it can
    // no longer be used.
    //
    // So how do we know the difference between an ACTUAL "failure" versus a
    // purposeful "failure" ?
    // Because if the failure comes from cancelling the plan, the server reply
    // transaction will have
    // IsCancelled() set to true.
    //
    // (Therefore theRequest.SendTransaction is smart enough to check for that.)

    OTAPI_Func theRequest(DEPOSIT_PAYMENT_PLAN, NOTARY_ID, NYM_ID,
                          strRecipientAcctID, THE_PAYMENT_PLAN);
    string strResponse =
        theRequest.SendTransaction(theRequest, "CANCEL_PAYMENT_PLAN");
    return strResponse;
}

// TRIGGER CLAUSE (on running smart contract)  -- TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::trigger_clause(const string& NOTARY_ID, const string& NYM_ID,
                             const string& STR_TRANS_NUM,
                             const string& CLAUSE_NAME, const string& STR_PARAM)
{
    OTAPI_Func ot_Msg;

    //  int32_t OTAPI_Wrap::triggerClause(const char* NOTARY_ID,
    //                                    const char * NYM_ID,
    //                                    const char * TRANSACTION_NUMBER,
    //                                    const char * CLAUSE_NAME,
    //                                    const char * STR_PARAM);

    OTAPI_Func theRequest(TRIGGER_CLAUSE, NOTARY_ID, NYM_ID, STR_TRANS_NUM,
                          CLAUSE_NAME, STR_PARAM);
    string strResponse = theRequest.SendRequest(theRequest, "TRIGGER_CLAUSE");

    return strResponse;
}

// WITHDRAW CASH  -- TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::withdraw_cash(const string& NOTARY_ID, const string& NYM_ID,
                            const string& ACCT_ID, int64_t AMOUNT)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(WITHDRAW_CASH, NOTARY_ID, NYM_ID, ACCT_ID, AMOUNT);
    string strResponse =
        theRequest.SendTransaction(theRequest, "WITHDRAW_CASH");

    return strResponse;
}

// WITHDRAW VOUCHER  -- TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::withdraw_voucher(const string& NOTARY_ID, const string& NYM_ID,
                               const string& ACCT_ID,
                               const string& RECIP_NYM_ID,
                               const string& STR_MEMO, int64_t AMOUNT)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(WITHDRAW_VOUCHER, NOTARY_ID, NYM_ID, ACCT_ID,
                          RECIP_NYM_ID, STR_MEMO, AMOUNT);
    string strResponse =
        theRequest.SendTransaction(theRequest, "WITHDRAW_VOUCHER");

    return strResponse;
}

// PAY DIVIDEND  -- TRANSACTION
//
OT_MADE_EASY_OT string
    MadeEasy::pay_dividend(const string& NOTARY_ID, const string& NYM_ID,
                           const string& SOURCE_ACCT_ID,
                           const string& SHARES_INSTRUMENT_DEFINITION_ID,
                           const string& STR_MEMO, int64_t AMOUNT_PER_SHARE)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(PAY_DIVIDEND, NOTARY_ID, NYM_ID, SOURCE_ACCT_ID,
                          SHARES_INSTRUMENT_DEFINITION_ID, STR_MEMO,
                          AMOUNT_PER_SHARE);
    string strResponse = theRequest.SendTransaction(theRequest, "PAY_DIVIDEND");

    return strResponse;
}

OT_MADE_EASY_OT string
    MadeEasy::deposit_cheque(const string& NOTARY_ID, const string& NYM_ID,
                             const string& ACCT_ID, const string& STR_CHEQUE)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(DEPOSIT_CHEQUE, NOTARY_ID, NYM_ID, ACCT_ID,
                          STR_CHEQUE);
    string strResponse = theRequest.SendTransaction(
        theRequest, "DEPOSIT_CHEQUE"); // <========================;

    return strResponse;
}

OT_MADE_EASY_OT string
    MadeEasy::get_market_list(const string& NOTARY_ID, const string& NYM_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_MARKET_LIST, NOTARY_ID, NYM_ID);
    string strResponse = theRequest.SendRequest(
        theRequest, "GET_MARKET_LIST"); // <========================;

    return strResponse;
}

// int32_t OTAPI_Wrap::getMarketOffers(const char* NOTARY_ID,
//                           const char * NYM_ID,
//                           const char * MARKET_ID,
//                           const char * MAX_DEPTH)

OT_MADE_EASY_OT string
    MadeEasy::get_market_offers(const string& NOTARY_ID, const string& NYM_ID,
                                const string& MARKET_ID, int64_t MAX_DEPTH)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_MARKET_OFFERS, NOTARY_ID, NYM_ID, MARKET_ID,
                          MAX_DEPTH);
    string strResponse = theRequest.SendRequest(
        theRequest, "GET_MARKET_OFFERS"); // <========================;

    return strResponse;
}

OT_MADE_EASY_OT string MadeEasy::get_nym_market_offers(const string& NOTARY_ID,
                                                       const string& NYM_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_NYM_MARKET_OFFERS, NOTARY_ID, NYM_ID);
    string strResponse = theRequest.SendRequest(
        theRequest, "GET_NYM_MARKET_OFFERS"); // <========================;

    return strResponse;
}

OT_MADE_EASY_OT string
    MadeEasy::get_market_recent_trades(const string& NOTARY_ID,
                                       const string& NYM_ID,
                                       const string& MARKET_ID)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(GET_MARKET_RECENT_TRADES, NOTARY_ID, NYM_ID,
                          MARKET_ID);
    string strResponse = theRequest.SendRequest(
        theRequest, "GET_MARKET_RECENT_TRADES"); // <========================;

    return strResponse;
}

OT_MADE_EASY_OT string
    MadeEasy::adjust_usage_credits(const string& NOTARY_ID,
                                   const string& USER_NYM_ID,
                                   const string& TARGET_NYM_ID,
                                   const string& ADJUSTMENT)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(ADJUST_USAGE_CREDITS, NOTARY_ID, USER_NYM_ID,
                          TARGET_NYM_ID, ADJUSTMENT);
    string strResponse = theRequest.SendRequest(
        theRequest, "ADJUST_USAGE_CREDITS"); // <========================;

    return strResponse;
}

// Imports a purse into the wallet.

// NOTE:   UNUSED currently.
OT_MADE_EASY_OT bool MadeEasy::importCashPurse(
    const string& notaryID, const string& nymID,
    const string& instrumentDefinitionID, string& userInput, bool isPurse)
{
    //  otOut << "OT_ME_importCashPurse, notaryID:" << notaryID << "
    // nymID:" << nymID << " instrumentDefinitionID:" <<
    // instrumentDefinitionID);
    //  otOut << "OT_ME_importCashPurse, userInput purse:" <<
    // userInput <<);

    if (!isPurse) // it's not a purse. Must be a
                  // token, so let's create a purse
                  // for it.
    {
        //      otOut << "OT_ME_importCashPurse, isPurse:" +
        // isPurse)

        string purse =
            OTAPI_Wrap::CreatePurse(notaryID, instrumentDefinitionID, nymID,
                                    nymID); // nymID, nymID == owner, signer;

        if (!VerifyStringVal(purse)) {
            otOut << "OT_ME_importCashPurse: Error: "
                     "OT_API_CreatePurse returned null\n";
            return false;
        }
        //      otOut << "OT_ME_importCashPurse, OT_API_CreatePurse
        // return :" + purse);

        string newPurse = OTAPI_Wrap::Purse_Push(
            notaryID, instrumentDefinitionID, nymID, nymID, purse, userInput);
        if (!VerifyStringVal(newPurse)) {
            otOut << "OT_ME_importCashPurse: Error: "
                     "OT_API_Purse_Push returned null\n";
            return false;
        }
        //      otOut << "OT_ME_importCashPurse, OT_API_Purse_Push
        // returned :" + newPurse);
        userInput = newPurse;
    }
    //  otOut << "OT_ME_importCashPurse, Before calling
    // OT_API_Wallet_ImportPurse, final purse:" + userInput);
    //  otOut << "OT_ME_importCashPurse just before api ,
    // notaryID:" + notaryID + " nymID:" + nymID + " instrumentDefinitionID:" +
    // instrumentDefinitionID);

    // Here we have either a purse that was passed in, or a purse that we
    // created so
    // we could add the token that was passed in. Either way, we have a purse
    // now, so
    // let's import it into the wallet.
    //
    return 1 == OTAPI_Wrap::Wallet_ImportPurse(notaryID, instrumentDefinitionID,
                                               nymID, userInput);
}

// processCashPurse pops the selected tokens off of oldPurse, changes their
// owner to recipientNymID,
// and pushes them onto newPurse, owned by recipientNymID. Meanwhile any
// unselected tokens are pushed
// onto newPurseUnselectedTokens, owned by nymID, which is saved to local
// storage (overwriting...)
// newPurse is returned from this function.
//
// Thus, for example, if there's a problem depositing/exporting/exchanging
// newPurse, then it needs
// to be merged back into the old purse again, which is otherwise still missing
// those tokens. (We
// should keep a copy of them in the payments outbox or something like that, in
// the meantime.)
//
// What is newPurseForSender for?
// Sometimes when processCashPurse is called, a Nym is just removing tokens from
// his purse so he can
// deposit them into his own account. Meaning the "sender" Nym (who owns the
// purse) is the same as the
// "recipient" Nym (who owns the account.) In which case, newPurse (for
// recipient) and newPurseForSender
// will contain the exact same thing. But in the case where they are different
// Nyms (like if I am
// exporting these tokens from my purse in order to give them to someone else)
// then I will want a copy
// of the exported purse for the recipient, and a copy of the same exported
// purse for the sender.
// processCashPurse returns both of those for me. The reason is because
// otherwise, if I just encrypted
// some of my cash tokens to some external Nym, then only THAT Nym's private key
// will ever open them up
// again. Even if I have them in my outpayments box, I can never recover them
// because I can never again
// decrypt them. Therefore I make a special copy of the outgoing purse which is
// encrypted to my own key,
// and put that into my outpayments box instead of the one I sent to the
// recipient (or including both
// of them.) That way the cash can still be recovered if necessary, from my
// outpayments box, and re-imported
// back into my cash purse again.
//
OT_MADE_EASY_OT bool MadeEasy::processCashPurse(
    string& newPurse, string& newPurseForSender, const string& notaryID,
    const string& instrumentDefinitionID, const string& nymID, string& oldPurse,
    const vector<string>& selectedTokens, const string& recipientNymID,
    bool bPWProtectOldPurse, bool bPWProtectNewPurse)
{
    // By this point, we know that "selected tokens" has a size of 0, or MORE
    // THAN ONE. (But NOT 1 exactly.)
    // (At least, if this function was called by exportCashPurse.)
    string strLocation = "OT_ME_processCashPurse";

    // This block handles cases where NO TOKENS ARE SELECTED.
    //
    // (Meaning: "PROCESS" THEM ALL.)
    //
    if (selectedTokens.size() < 1) {
        // newPurse is created, OWNED BY RECIPIENT.
        //
        newPurse = (bPWProtectNewPurse
                        ? OTAPI_Wrap::CreatePurse_Passphrase(
                              notaryID, instrumentDefinitionID, nymID)
                        : OTAPI_Wrap::CreatePurse(
                              notaryID, instrumentDefinitionID, recipientNymID,
                              nymID)); // recipientNymID is owner,
                                       // nymID is signer;

        if (!VerifyStringVal(newPurse)) {
            otOut << strLocation << ": "
                  << (bPWProtectNewPurse ? "OT_API_CreatePurse_Passphrase"
                                         : "OT_API_CreatePurse")
                  << " returned null\n";
            return false;
        }

        // We'll create an extra copy of the newPurse, which is encrypted to the
        // sender (instead of the recipient or
        // some passphrase.) We'll call it newPurseForSender. This way the
        // sender can later have the option to recover
        // the cash from his outbox.
        //
        newPurseForSender =
            OTAPI_Wrap::CreatePurse(notaryID, instrumentDefinitionID, nymID,
                                    nymID); // nymID is owner, nymID is signer;

        if (!VerifyStringVal(newPurseForSender)) {
            otOut << strLocation
                  << ": Failure: OT_API_CreatePurse returned null\n";
            return false;
        }

        // Iterate through the OLD PURSE. (as tempOldPurse.)
        //
        int32_t count =
            OTAPI_Wrap::Purse_Count(notaryID, instrumentDefinitionID, oldPurse);
        string tempOldPurse = oldPurse;

        for (int32_t i = 0; i < count; ++i) {
            // Peek into TOKEN, from the top token on the stack. (And it's STILL
            // on top after this call.)
            //
            string token = OTAPI_Wrap::Purse_Peek(
                notaryID, instrumentDefinitionID, nymID, tempOldPurse);

            // Now pop the token off of tempOldPurse (our iterator for the old
            // purse).
            // Store updated copy of purse (sans token) into "str1".
            //
            string str1 = OTAPI_Wrap::Purse_Pop(
                notaryID, instrumentDefinitionID, nymID, tempOldPurse);

            if (!VerifyStringVal(token) || !VerifyStringVal(str1)) {
                otOut << strLocation
                      << ": OT_API_Purse_Peek or OT_API_Purse_Pop "
                         "returned null... SHOULD NEVER HAPPEN. "
                         "Returning null.\n";
                return false;
            }

            // Since pop succeeded, copy the output to tempOldPurse
            // (for next iteration, in case any continues happen below.)
            // Now tempOldPurse contains what it did before, MINUS ONE TOKEN.
            // (The exported one.)
            //
            tempOldPurse = str1;

            string strSender = bPWProtectOldPurse ? oldPurse : nymID;
            string strRecipient =
                bPWProtectNewPurse ? newPurse : recipientNymID;

            string strSenderAsRecipient =
                nymID; // Used as the "owner" of newPurseForSender. (So the
                       // sender can recover his sent coins that got encrypted
                       // to someone else's key.);

            // Change the OWNER on token, from NymID to RECIPIENT.
            // (In this block, we change ALL the tokens in the purse.)
            //
            string exportedToken = OTAPI_Wrap::Token_ChangeOwner(
                notaryID, instrumentDefinitionID, token, nymID, // signer ID
                strSender,                                      // old owner
                strRecipient);                                  // new owner
            // If change failed, then continue.
            //
            if (!VerifyStringVal(exportedToken)) {
                otOut << strLocation << ": 1, OT_API_Token_ChangeOwner "
                                        "returned null...(should never "
                                        "happen) Returning null.\n";
                return false;
            }

            // SAVE A COPY FOR THE SENDER...
            //
            string retainedToken = OTAPI_Wrap::Token_ChangeOwner(
                notaryID, instrumentDefinitionID, token, nymID, // signer ID
                strSender,                                      // old owner
                strSenderAsRecipient);                          // new owner
            // If change failed, then continue.
            //
            if (!VerifyStringVal(retainedToken)) {
                otOut << strLocation << ":  2, OT_API_Token_ChangeOwner "
                                        "returned null...(should never "
                                        "happen) Returning null.\n";
                return false;
            }

            //          strSender    = bPWProtectOldPurse ? "" : nymID // unused
            // here. not needed.
            strRecipient = bPWProtectNewPurse ? "" : recipientNymID;

            // PUSH the EXPORTED TOKEN (new owner) into the new purse (again,
            // recipient/newPurse is new owner) and save results in
            // "strPushedForRecipient".
            // Results are, FYI, newPurse+exportedToken.
            //
            string strPushedForRecipient = OTAPI_Wrap::Purse_Push(
                notaryID, instrumentDefinitionID,
                nymID,        // server, asset, signer
                strRecipient, // owner is either nullptr (for password-protected
                              // purse) or recipientNymID
                newPurse, exportedToken); // purse, token

            // If push failed, then continue.
            if (!VerifyStringVal(strPushedForRecipient)) {
                otOut << strLocation
                      << ":  OT_API_Purse_Push 1 returned null... "
                         "(should never happen) Returning null.\n";
                return false;
            }

            // PUSH the RETAINED TOKEN (copy for original owner) into the
            // newPurseForSender and save results in "strPushedForRetention".
            // Results are, FYI, newPurseForSender+retainedToken.
            //
            string strPushedForRetention = OTAPI_Wrap::Purse_Push(
                notaryID, instrumentDefinitionID,
                nymID,                // server, asset, signer
                strSenderAsRecipient, // This version of the purse is the
                // outgoing copy (for the SENDER's notes).
                // Thus strSenderAsRecipient.
                newPurseForSender, retainedToken); // purse, token

            // If push failed, then continue.
            if (!VerifyStringVal(strPushedForRetention)) {
                otOut << strLocation
                      << ":  OT_API_Purse_Push 2 returned null... "
                         "(should never happen) Returning null.\n";
                return false;
            }

            // Since push succeeded, copy "strPushedForRecipient" (containing
            // newPurse         +exportedToken) into newPurse.
            // Since push succeeded, copy "strPushedForRetention" (containing
            // newPurseForSender+retainedToken) into newPurseForSender.
            //
            newPurse = strPushedForRecipient;
            newPurseForSender = strPushedForRetention;
        } // for

        // Save tempOldPurse to local storage. (For OLD Owner.)
        // By now, all of the tokens have been popped off of this purse, so it
        // is EMPTY.
        // We're now saving the empty purse, since the user exported all of the
        // tokens.
        //
        // THERE MAYBE SHOULD BE AN EXTRA MODAL HERE, that says,
        // "Moneychanger will now save your purse, EMPTY, back to local storage.
        // Are you sure you want to do this?"
        //

        if (!bPWProtectOldPurse) // If old purse is NOT password-protected (that
                                 // is, it's encrypted to a Nym.)
        {
            if (!OTAPI_Wrap::SavePurse(notaryID, instrumentDefinitionID, nymID,
                                       tempOldPurse)) // if FAILURE.
            {
                // No error message if saving fails??
                // No modal?
                //
                // FT: adding log.
                otOut << strLocation << ": OT_API_SavePurse "
                                        "FAILED. SHOULD NEVER HAPPEN!!!!!!\n";
                return false;
            }
        }
        else // old purse IS password protected. (So return its updated
               // version.)
        {
            oldPurse = tempOldPurse; // We never cared about this with Nym-owned
                                     // old purse, since it saves to storage
                                     // anyway, in the above block. But now in
                                     // the case of password-protected purses,
                                     // we set the oldPurse to contain the new
                                     // version of itself (containing the tokens
                                     // that had been left unselected) so the
                                     // caller can do what he wills with it.;
        }
    }

    // Else, SPECIFIC TOKENS were selected, so process those only...
    //
    else {
        //      otOut << "Tokens in Cash Purse being processed");

        // newPurseSelectedTokens is created (CORRECTLY) with recipientNymID as
        // owner. (Or with a symmetric key / passphrase.)
        // newPurseUnSelectedTokens is created (CORRECTLY) with NymID as owner.
        // (Unselected tokens aren't being exported...)
        //
        string newPurseUnSelectedTokens = OTAPI_Wrap::Purse_Empty(
            notaryID, instrumentDefinitionID, nymID,
            oldPurse); // Creates an empty copy of oldPurse.;
        string newPurseSelectedTokens =
            (bPWProtectNewPurse
                 ? OTAPI_Wrap::CreatePurse_Passphrase(
                       notaryID, instrumentDefinitionID, nymID)
                 : OTAPI_Wrap::CreatePurse(notaryID, instrumentDefinitionID,
                                           recipientNymID,
                                           nymID)); // recipientNymID = owner,
                                                    // nymID = signer;
        string newPurseSelectedForSender = OTAPI_Wrap::CreatePurse(
            notaryID, instrumentDefinitionID, nymID,
            nymID); // nymID = owner, nymID = signer. This is a copy of
                    // newPurseSelectedTokens that's encrypted to the SENDER
                    // (for putting in his outpayments box, so he can still
                    // decrypt if necessary.);

        if (!VerifyStringVal(newPurseSelectedForSender)) {
            otOut << strLocation << ":  OT_API_CreatePurse returned null\n";
            return false;
        }
        if (!VerifyStringVal(newPurseSelectedTokens)) {
            otOut << strLocation
                  << ":  OT_API_CreatePurse or "
                     "OT_API_CreatePurse_Passphrase returned null\n";
            return false;
        }
        if (!VerifyStringVal((newPurseUnSelectedTokens))) {
            otOut << strLocation << ":  OT_API_Purse_Empty returned null\n";
            return false;
        }

        // Iterate through oldPurse, using tempOldPurse as iterator.
        //
        int32_t count =
            OTAPI_Wrap::Purse_Count(notaryID, instrumentDefinitionID, oldPurse);
        string tempOldPurse = oldPurse;

        for (int32_t i = 0; i < count; ++i) {
            // Peek at the token on top of the stack.
            // (Without removing it.)
            //
            string token = OTAPI_Wrap::Purse_Peek(
                notaryID, instrumentDefinitionID, nymID, tempOldPurse);

            // Remove the top token from the stack, and return the updated stack
            // in "str1".
            //
            string str1 = OTAPI_Wrap::Purse_Pop(
                notaryID, instrumentDefinitionID, nymID, tempOldPurse);

            if (!VerifyStringVal(str1) || !VerifyStringVal(token)) {
                otOut << strLocation
                      << ":  OT_API_Purse_Peek or "
                         "OT_API_Purse_Pop returned null... returning Null. "
                         "(SHOULD NEVER HAPPEN.)\n";
                return false;
            }

            // Putting updated purse into iterator, so any subsequent continues
            // will work properly.
            //
            tempOldPurse = str1;

            // Grab the TokenID for that token. (Token still has OLD OWNER.)
            //
            string tokenID = OTAPI_Wrap::Token_GetID(
                notaryID, instrumentDefinitionID, token);

            if (!VerifyStringVal(tokenID)) {
                otOut << strLocation
                      << ":  OT_API_Token_GetID returned null... "
                         "SHOULD NEVER HAPPEN. Returning now.\n";
                return false;
            }

            // At this point, we check TokenID (identifying the current token)
            // to see if it's on the SELECTED LIST.
            //
            if (find(selectedTokens.begin(), selectedTokens.end(), tokenID) !=
                selectedTokens.end()) // We ARE exporting
                                      // this token. (Its
                                      // ID was on the
                                      // list.)
            {
                // CHANGE OWNER from NYM to RECIPIENT
                // "token" will now contain the EXPORTED TOKEN, with the NEW
                // OWNER.
                //
                string strSender = bPWProtectOldPurse ? oldPurse : nymID;
                string strRecipient = bPWProtectNewPurse
                                          ? newPurseSelectedTokens
                                          : recipientNymID;

                string strSenderAsRecipient =
                    nymID; // Used as the "owner" of newPurseSelectedForSender.
                           // (So the sender can recover his sent coins that got
                           // encrypted to someone else's key.);

                string exportedToken = OTAPI_Wrap::Token_ChangeOwner(
                    notaryID, instrumentDefinitionID,
                    token,         // server, asset, token,;
                    nymID,         // signer nym
                    strSender,     // old owner
                    strRecipient); // new owner
                if (!VerifyStringVal(exportedToken)) {
                    otOut << strLocation << ": 1  OT_API_Token_ChangeOwner "
                                            "returned null... SHOULD NEVER "
                                            "HAPPEN. Returning now.\n";
                    return false;
                }

                string retainedToken = OTAPI_Wrap::Token_ChangeOwner(
                    notaryID, instrumentDefinitionID,
                    token,                 // server, asset, token,;
                    nymID,                 // signer nym
                    strSender,             // old owner
                    strSenderAsRecipient); // new owner
                if (!VerifyStringVal(retainedToken)) {
                    otOut << strLocation << ": 2  OT_API_Token_ChangeOwner "
                                            "returned null... SHOULD NEVER "
                                            "HAPPEN. Returning now.\n";
                    return false;
                }

                // Push exported version of token into new purse for recipient
                // (for selected tokens.)
                //
                //              strSender    = bPWProtectOldPurse ? "" : nymID
                // // unused here. Not needed.
                strRecipient = bPWProtectNewPurse ? "" : recipientNymID;

                string strPushedForRecipient = OTAPI_Wrap::Purse_Push(
                    notaryID, instrumentDefinitionID,
                    nymID,        // server, asset, signer;
                    strRecipient, // owner is either nullptr (for
                    // password-protected purse) or recipientNymID
                    newPurseSelectedTokens, exportedToken); // purse, token
                if (!VerifyStringVal(strPushedForRecipient)) {
                    otOut << strLocation
                          << ":  OT_API_Purse_Push "
                             "newPurseSelectedTokens returned null... "
                             "SHOULD NEVER HAPPEN (returning.)\n";
                    return false;
                }

                // Done: push a copy of these into a purse for the original
                // owner as well, so he has his OWN copy
                // to save in his payments outbox (that HE can decrypt...) so if
                // the cash is lost, for example, he can still
                // recover it. If the recipient receives it and deposits it
                // correctly, the cash in your payment outbox is now
                // worthless and can be discarded, although its existence may be
                // valuable to you as a receipt.
                //
                string strPushedForRetention = OTAPI_Wrap::Purse_Push(
                    notaryID, instrumentDefinitionID,
                    nymID, // server, asset, signer;
                    strSenderAsRecipient, newPurseSelectedForSender,
                    retainedToken); // purse, token
                if (!VerifyStringVal(strPushedForRetention)) {
                    otOut << strLocation
                          << ":  OT_API_Purse_Push "
                             "newPurseSelectedForSender returned null... "
                             "SHOULD NEVER HAPPEN (returning.)\n";
                    return false;
                }

                newPurseSelectedTokens = strPushedForRecipient;
                newPurseSelectedForSender = strPushedForRetention;

            }
            else // The token, this iteration, is NOT being exported, but is
                   // remaining with the original owner.
            {
                string strSender = bPWProtectOldPurse ? "" : nymID;

                string str = OTAPI_Wrap::Purse_Push(
                    notaryID, instrumentDefinitionID,
                    nymID,     // server, asset, signer;
                    strSender, // owner is either nullptr (for
                               // password-protected
                               // purse) or nymID
                    newPurseUnSelectedTokens, token); // purse, token
                if (!VerifyStringVal(str)) {
                    otOut << strLocation
                          << ": OT_API_Purse_Push "
                             "newPurseUnSelectedTokens returned null... "
                             "SHOULD NEVER HAPPEN. Returning false.\n";
                    return false;
                }

                newPurseUnSelectedTokens = str;
            }
        } // for

        if (!bPWProtectOldPurse) // If old purse is NOT password-protected (that
                                 // is, it's encrypted to a Nym.)
        {
            if (!OTAPI_Wrap::SavePurse(notaryID, instrumentDefinitionID, nymID,
                                       newPurseUnSelectedTokens)) // if FAILURE.
            {
                // No error message if saving fails??
                // No modal?
                //
                // FT: adding log.
                otOut << strLocation << ":  OT_API_SavePurse "
                                        "FAILED. SHOULD NEVER HAPPEN!!!!!!\n";
                return false;
            }
        }
        else // old purse IS password protected. (So return its updated
               // version.)
        {
            oldPurse =
                newPurseUnSelectedTokens; // We never cared about this with
                                          // Nym-owned old purse, since it saves
                                          // to storage anyway, in the above
                                          // block. But now in the case of
                                          // password-protected purses, we set
                                          // the oldPurse to contain the new
                                          // version of itself (containing the
                                          // tokens that had been left
                                          // unselected) so the caller can do
                                          // what he wills with it.;
        }

        // The SELECTED tokens (with Recipient as owner of purse AND tokens
        // within) are returned as the "newPurse".
        // The SELECTED tokens (with Sender as owner of purse AND tokens within)
        // are returned as "newPurseForSender".
        //
        newPurse = newPurseSelectedTokens;
        newPurseForSender = newPurseSelectedForSender;
    }

    return true;
}

// Input: server ID, instrumentDefinitionID, Nym of current owner, existing
// purse, list of
// selected tokens, Nym of Recipient, and bool bPasswordProtected.
// Returns: "new Purse"
//
OT_MADE_EASY_OT string
    MadeEasy::exportCashPurse(const string& notaryID,
                              const string& instrumentDefinitionID,
                              const string& nymID, const string& oldPurse,
                              const vector<string>& selectedTokens,
                              string& recipientNymID, bool bPasswordProtected,
                              string& strRetainedCopy)
{
    //  otOut << "OT_ME_exportCashPurse starts, selectedTokens:" <<
    // selectedTokens << "\n";
    //  Utility.setObj(null);

    if (!bPasswordProtected) {
        // If no recipient, then recipient == Nym.
        //
        if (!VerifyStringVal(recipientNymID) || (recipientNymID.size() == 0)) {
            otOut << "OT_ME_exportCashPurse: recipientNym empty--using NymID "
                     "for recipient instead: " << nymID << "\n";
            recipientNymID = nymID;
        }

        if (!(recipientNymID == nymID)) {
            // Even though we don't use this variable after this point,
            // we've still done something important: loaded and possibly
            // downloaded the recipient Nym, so that later in this function
            // we can reference that recipientNymID in other calls and we know
            // it will work.
            //
            string recipientPubKey = load_or_retrieve_encrypt_key(
                notaryID, nymID, recipientNymID); // this function handles
                                                  // partial IDs for recipient.;

            if (!VerifyStringVal(recipientPubKey)) {
                otOut << "OT_ME_exportCashPurse: recipientPubKey is null\n";
                return "";
            }
        }
    }

    // By this point, we have verified that we can load the public key for the
    // recipient.
    // (IF the exported purse isn't meant to be password-protected.)
    //
    string token = "";
    string exportedToken = "";
    string exportedPurse = "";

    // Next I create another "newPurse" by calling this function.
    //
    string newPurse = ""; // for recipient;
    string newPurseForSender = "";
    string copyOfOldPurse = oldPurse;
    bool bSuccessProcess = processCashPurse(
        newPurse, newPurseForSender, notaryID, instrumentDefinitionID, nymID,
        copyOfOldPurse, selectedTokens, recipientNymID, false,
        bPasswordProtected);

    if (bSuccessProcess) {
        strRetainedCopy = newPurseForSender;
    }

    // Whatever is returned from that function, I return here also. Presumably a
    // purse...
    //
    return newPurse;
}

OT_MADE_EASY_OT int32_t MadeEasy::depositCashPurse(
    const string& notaryID, const string& instrumentDefinitionID,
    const string& nymID, const string& oldPurse,
    const vector<string>& selectedTokens, const string& accountID,
    bool bReimportIfFailure) // So we don't re-import a purse that wasn't
                             // internal to begin with.
{
    string recipientNymID = OTAPI_Wrap::GetAccountWallet_NymID(accountID);
    if (!VerifyStringVal(recipientNymID)) {
        otOut << "\ndepositCashPurse: Unable to find recipient Nym based on "
                 "myacct. \n";
        return -1;
    }

    bool bPasswordProtected = OTAPI_Wrap::Purse_HasPassword(notaryID, oldPurse);

    string newPurse;               // being deposited.;
    string newPurseForSender = ""; // Probably unused in this case.;
    string copyOfOldPurse = oldPurse;
    bool bSuccessProcess = processCashPurse(
        newPurse, newPurseForSender, notaryID, instrumentDefinitionID, nymID,
        copyOfOldPurse, selectedTokens, recipientNymID, bPasswordProtected,
        false);

    if (!bSuccessProcess || !VerifyStringVal(newPurse)) {
        otOut << "OT_ME_depositCashPurse: new Purse is empty, after processing "
                 "it for deposit. \n";
        return -1;
    }

    OTAPI_Func ot_Msg;
    OTAPI_Func theRequest(DEPOSIT_CASH, notaryID, recipientNymID, accountID,
                          newPurse);
    string strResponse = theRequest.SendTransaction(
        theRequest, "DEPOSIT_CASH"); // <========================;

    string strAttempt = "deposit_cash";

    // HERE, WE INTERPRET THE SERVER REPLY, WHETHER SUCCESS, FAIL, OR ERROR...

    int32_t nInterpretReply = InterpretTransactionMsgReply(
        notaryID, recipientNymID, accountID, strAttempt, strResponse);

    if (1 == nInterpretReply) {
        // Download all the intermediary files (account balance, inbox, outbox,
        // etc)
        // since they have probably changed from this operation.
        //
        bool bRetrieved =
            retrieve_account(notaryID, recipientNymID, accountID,
                             true); // bForceDownload defaults to false.;

        otOut << "\nServer response (" << strAttempt
              << "): SUCCESS depositing cash!\n";
        otOut << string(bRetrieved ? "Success" : "Failed")
              << " retrieving intermediary files for account.\n";
    }
    else // failure. (so we re-import the cash, so as not to lose it...)
    {

        if (!bPasswordProtected && bReimportIfFailure) {
            bool importStatus = OTAPI_Wrap::Wallet_ImportPurse(
                notaryID, instrumentDefinitionID, recipientNymID, newPurse);
            otOut << "Since failure in OT_ME_depositCashPurse, "
                     "OT_API_Wallet_ImportPurse called. Status of "
                     "import: " << importStatus << "\n";

            if (!importStatus) {
                // Raise the alarm here that we failed depositing the purse, and
                // then we failed
                // importing it back into our wallet again.
                otOut << "Error: Failed depositing the cash purse, and then "
                         "failed re-importing it back to wallet. Therefore YOU "
                         "must copy the purse NOW and save it to a safe place! "
                         "\n";

                cout << newPurse << "\n";

                otOut << "AGAIN: Be sure to copy the above purse "
                         "to a safe place, since it FAILED to "
                         "deposit and FAILED to re-import back "
                         "into the wallet. \n";
            }
        }
        else {
            otOut << "Error: Failed depositing the cash purse. "
                     "Therefore YOU must copy the purse NOW and "
                     "save it to a safe place! \n";

            cout << newPurse << "\n";

            otOut << "AGAIN: Be sure to copy the above purse to a "
                     "safe place, since it FAILED to deposit. \n";
        }

        return -1;
    }

    //
    // Return status to caller.
    //
    return nInterpretReply;
}

OT_MADE_EASY_OT bool MadeEasy::exchangeCashPurse(
    const string& notaryID, const string& instrumentDefinitionID,
    const string& nymID, string& oldPurse, const vector<string>& selectedTokens)
{
    //  Utility.setObj(null);
    //  otOut << " Cash Purse exchange starts, selectedTokens:" +
    // selectedTokens + "\n")

    string newPurse;
    string newPurseForSender = ""; // Probably unused in this case.;

    bool bProcessSuccess = processCashPurse(
        newPurse, newPurseForSender, notaryID, instrumentDefinitionID, nymID,
        oldPurse, selectedTokens, nymID, false,
        false); // bIsPasswordProtected=false;

    if (bProcessSuccess && !VerifyStringVal(newPurse)) {
        otOut << "OT_ME_exchangeCashPurse: Before server OT_API_exchangePurse "
                 "call, new Purse is empty. Returning false.\n";
        return false;
    }

    OTAPI_Func ot_Msg;
    OTAPI_Func theRequest(EXCHANGE_CASH, notaryID, nymID,
                          instrumentDefinitionID, newPurse);
    string strResponse = theRequest.SendTransaction(
        theRequest, "EXCHANGE_CASH"); // <========================;

    if (!VerifyStringVal(strResponse)) {
        otOut << "IN OT_ME_exchangeCashPurse: theRequest.SendTransaction(() "
                 "failed. (I give up.) \n";

        bool importStatus = OTAPI_Wrap::Wallet_ImportPurse(
            notaryID, instrumentDefinitionID, nymID, newPurse);
        otOut << "Since failure in OT_ME_exchangeCashPurse, "
                 "OT_API_Wallet_ImportPurse called, status of import: "
              << string(importStatus ? "true" : "false") << "\n";
        if (!importStatus) {
            //          Utility.setObj(newPurse)
        }

        return false;
    }

    //  otOut << "OT_ME_exchangeCashPurse ends, status:
    // success.\n")

    return true;
}

OT_MADE_EASY_OT string
    MadeEasy::deposit_purse(const string& NOTARY_ID, const string& NYM_ID,
                            const string& ACCT_ID, const string& STR_PURSE)
{
    OTAPI_Func ot_Msg;

    OTAPI_Func theRequest(DEPOSIT_CASH, NOTARY_ID, NYM_ID, ACCT_ID, STR_PURSE);
    string strResponse = theRequest.SendTransaction(
        theRequest, "DEPOSIT_CASH"); // <========================;

    return strResponse;
}

/*

DONE:  create nym, register nym, issue instrument definition, send transfer,
accept entire
inbox, write cheque.

Next ones:  show purse, withdraw cash, deposit cash, withdraw voucher, deposit
cheque.

Need to add functions (like check_nym above) for all of these:

attr OTAPI_Func::REGISTER_NYM (register nym)DONE
attr OTAPI_Func::DELETE_NYM
attr OTAPI_Func::CHECK_NYM DONE
attr OTAPI_Func::SEND_USER_MESSAGE DONE
attr OTAPI_Func::ISSUE_ASSET_TYPE               DONE
attr OTAPI_Func::ISSUE_BASKET                   DONE
attr OTAPI_Func::CREATE_ASSET_ACCT DONE
attr OTAPI_Func::DELETE_ASSET_ACCT
attr OTAPI_Func::EXCHANGE_BASKET                DONE
attr OTAPI_Func::PROCESS_INBOX                  DONE
attr OTAPI_Func::DEPOSIT_CASH                   DONE
attr OTAPI_Func::EXCHANGE_CASH
attr OTAPI_Func::DEPOSIT_CHEQUE                 DONE
attr OTAPI_Func::WITHDRAW_VOUCHER               DONE
attr OTAPI_Func::WITHDRAW_CASH                  DONE
attr OTAPI_Func::PAY_DIVIDEND                   DONE
attr OTAPI_Func::GET_CONTRACT                   DONE
attr OTAPI_Func::SEND_TRANSFER                  DONE
attr OTAPI_Func::GET_MARKET_LIST                DONE
attr OTAPI_Func::CREATE_MARKET_OFFER DONE
attr OTAPI_Func::KILL_MARKET_OFFER              DONE
attr OTAPI_Func::KILL_PAYMENT_PLAN              DONE
attr OTAPI_Func::GET_NYM_MARKET_OFFERS          DONE
attr OTAPI_Func::GET_MARKET_OFFERS              DONE
attr OTAPI_Func::GET_MARKET_RECENT_TRADES
attr OTAPI_Func::GET_MINT DONE
attr OTAPI_Func::QUERY_ASSET_TYPES DONE
attr OTAPI_Func::GET_BOX_RECEIPT DONE

--- Activate Payment Plan

------ TANGENT -----------------------------------------
Use cases that do not require a server message, and thus will have
representative
functions in ot_made_easy.ot EVEN WHEN there is no corresponding server message
in ot.
--- stat wallet               DONE
--- Stat cash purse           DONE
--- Stat account              DONE
--- Stat account inbox        DONE
--- Stat account outbox       DONE
--- Stat payment inbox        DONE
--- Stat record box           DONE
--- encode / decode           DONE
--- encrypt/decrypt           DONE
--- Password encrypt/decrypt  DONE
--- Sign / Verify             DONE
--- Create asset contract     DONE
--- Create server contract    DONE
--- Create symmetric key      DONE
--- Create pseudonym          DONE
--- Write cheque              DONE
--- Verify last acct receipt  DONE
--- Refresh (download latest) DONE
--- Refresh Nym               DONE
--- Propose Payment Plan
--- Confirm Payment Plan
--- Balance                   DONE
---

------ END TANGENT -------------------------------------


Here are parameters for the first group above.
(They are called in OTAPI_Func, this code is from there):

else if (funcType == DELETE_NYM)
{ OTAPI_Wrap::unregisterNym(notaryID, nymID); }
else if (funcType == GET_NYM_MARKET_OFFERS)
{ OTAPI_Wrap::getNym_MarketOffers(notaryID, nymID); }
else if (funcType == CREATE_ASSET_ACCT)
{ OTAPI_Wrap::registerAccount(notaryID, nymID, instrumentDefinitionID); }
else if (funcType == DELETE_ASSET_ACCT)
{ OTAPI_Wrap::deleteAssetAccount(notaryID, nymID, accountID); }
else if (funcType == EXCHANGE_BASKET)
{ OTAPI_Wrap::exchangeBasket(notaryID, nymID, instrumentDefinitionID, basket,
bBool); }
else if (funcType == GET_CONTRACT)
{ OTAPI_Wrap::getContract(notaryID, nymID, instrumentDefinitionID); }
else if (funcType == ISSUE_ASSET_TYPE)
{ OTAPI_Wrap::issueAssetType(notaryID, nymID, strData); }
else if (funcType == ISSUE_BASKET)
{ OTAPI_Wrap::issueBasket(notaryID, nymID, basket); }
else if (funcType == EXCHANGE_CASH)
{ OTAPI_Wrap::exchangePurse(notaryID, instrumentDefinitionID, nymID, strData); }
else if (funcType == KILL_MARKET_OFFER)
{ OTAPI_Wrap::cancelMarketOffer(notaryID, nymID, accountID, strData); }
else if (funcType == PROCESS_INBOX)
{ OTAPI_Wrap::processInbox(notaryID, nymID, accountID, strData); }
else if (funcType == DEPOSIT_CASH)
{ OTAPI_Wrap::notarizeDeposit(notaryID, nymID, accountID, strData); }
else if (funcType == DEPOSIT_CHEQUE)
{ OTAPI_Wrap::depositCheque(notaryID, nymID, accountID, strData); }
else if (funcType == WITHDRAW_CASH)
{ OTAPI_Wrap::notarizeWithdrawal(notaryID, nymID, accountID, strData); }
else if (funcType == WITHDRAW_VOUCHER)
{ OTAPI_Wrap::withdrawVoucher(notaryID, nymID, accountID, nymID2, strData,
strData2); }
else if (funcType == SEND_TRANSFER)
{ OTAPI_Wrap::notarizeTransfer(notaryID, nymID, accountID, accountID2,
strData, strData2); } // amount and note, for the last two.
else if (funcType == GET_MARKET_LIST)
{ OTAPI_Wrap::getMarketList(notaryID, nymID); }
else if (funcType == GET_MARKET_OFFERS)
{ OTAPI_Wrap::getMarketOffers(notaryID, nymID, strData, strData2); }
else if (funcType == GET_MARKET_RECENT_TRADES)
{ OTAPI_Wrap::getMarketRecentTrades(notaryID, nymID, strData); }
else if (funcType == CREATE_MARKET_OFFER)
{ OTAPI_Wrap::issueMarketOffer(notaryID, nymID, instrumentDefinitionID,
accountID, instrumentDefinitionID2,
accountID2,
strData, strData2, strData3, strData4, bBool);
}

*/
