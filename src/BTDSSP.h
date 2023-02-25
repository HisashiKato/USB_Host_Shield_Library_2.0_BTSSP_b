/* Copyright (C) 2012 Kristian Lauszus, TKJ Electronics. All rights reserved.

 This software may be distributed and modified under the terms of the GNU
 General Public License version 2 (GPL2) as published by the Free Software
 Foundation and appearing in the file GPL2.TXT included in the packaging of
 this file. Please note that GPL2 Section 2[b] requires that all works based
 on this software must also be made publicly available under the terms of
 the GPL2 ("Copyleft").

 Contact information
 -------------------

 Kristian Lauszus, TKJ Electronics
 Web      :  http://www.tkjelectronics.com
 e-mail   :  kristianl@tkjelectronics.com
   
 Modified 25 Feb 2023 by HisashiKato
 Web      :  http://kato-h.cocolog-nifty.com/khweblog/
 */

#ifndef _btdssp_h_
#define _btdssp_h_

#include "Usb.h"
#include "usbhid.h"

/* Bluetooth dongle data taken from descriptors */
#define BULK_MAXPKTSIZE         64 // Max size for ACL data

// Used in control endpoint header for HCI Commands
#define bmREQ_HCI_OUT USB_SETUP_HOST_TO_DEVICE|USB_SETUP_TYPE_CLASS|USB_SETUP_RECIPIENT_DEVICE


/* HCI event flags*/
                                                   //use
#define HCI_FLAG_CMD_COMPLETE           (1UL << 0)                  //hci_set_flag //hci_clear_flag
#define HCI_FLAG_CONNECT_COMPLETE       (1UL << 1) //hci_check_flag //hci_set_flag //hci_clear_flag
#define HCI_FLAG_DISCONNECT_COMPLETE    (1UL << 2) //hci_check_flag //hci_set_flag //hci_clear_flag
#define HCI_FLAG_REMOTE_NAME_COMPLETE   (1UL << 3)
#define HCI_FLAG_INCOMING_REQUEST       (1UL << 4)                  //hci_set_flag //hci_clear_flag
#define HCI_FLAG_READ_BDADDR            (1UL << 5)                  //hci_set_flag
#define HCI_FLAG_HID_DEVICE_FOUND       (1UL << 6)                  //hci_set_flag //hci_clear_flag
#define HCI_FLAG_CONNECT_EVENT          (1UL << 7)                  //hci_set_flag //hci_clear_flag


/* Macros for HCI event flag tests */
#define hci_check_flag(flag) (hci_event_flag & (flag))
#define hci_set_flag(flag) (hci_event_flag |= (flag))
#define hci_clear_flag(flag) (hci_event_flag &= ~(flag))

/* HCI Events managed */
#define EV_INQUIRY_COMPLETE                             0x01
#define EV_INQUIRY_RESULT                               0x02
#define EV_CONNECTION_COMPLETE                          0x03
#define EV_CONNECTION_REQUEST                           0x04
#define EV_DISCONNECTION_COMPLETE                       0x05
#define EV_AUTHENTICATION_COMPLETE                      0x06
#define EV_REMOTE_NAME_REQUEST_COMPLETE                 0x07
#define EV_ENCRYPTION_CHANGE                            0x08
#define EV_CHANGE_CONNECTION_LINK_KEY_COMPLETE          0x09
#define EV_READ_REMOTE_SUPPORTED_FEATURES_COMPLETE      0x0B
#define EV_READ_REMOTE_VERSION_INFORMATION_COMPLETE     0x0C
#define EV_QOS_SETUP_COMPLETE                           0x0D
#define EV_COMMAND_COMPLETE                             0x0E
#define EV_COMMAND_STATUS                               0x0F
#define EV_ROLE_CHANGED                                 0x12
#define EV_NUMBER_OF_COMPLETED_PACKETS                  0x13
#define EV_RETURN_LINK_KEYS                             0x15
#define EV_PIN_CODE_REQUEST                             0x16
#define EV_LINK_KEY_REQUEST                             0x17
#define EV_LINK_KEY_NOTIFICATION                        0x18

#define EV_LOOPBACK_COMMAND                             0x19
#define EV_DATA_BUFFER_OVERFLOW                         0x1A
#define EV_MAX_SLOTS_CHANGE                             0x1B
#define EV_PAGE_SCAN_REPETITION_MODE_CHANGE             0x20
#define EV_INQUIRY_RESULT_WITH_RSSI                     0x22
#define EV_READ_REMOTE_EXTENDED_FEATURES_COMPLETE       0x23
#define EV_EXTENDED_INQUIRY_RESULT                      0x2F 
#define EV_IO_CAPABILITY_REQUEST                        0x31
#define EV_IO_CAPABILITY_RESPONSE                       0x32
#define EV_USER_CONFIRMATION_REQUEST                    0x33
#define EV_SIMPLE_PAIRING_COMPLETE                      0x36


/* Bluetooth states for the different Bluetooth drivers */
#define L2CAP_WAIT                      0
#define L2CAP_DONE                      1

/* Used for HID Control channel */
#define L2CAP_CONTROL_CONNECT_REQUEST   2
#define L2CAP_CONTROL_CONFIG_REQUEST    3
#define L2CAP_CONTROL_SUCCESS           4
#define L2CAP_CONTROL_DISCONNECT        5

/* Used for HID Interrupt channel */
#define L2CAP_INTERRUPT_SETUP           6
#define L2CAP_INTERRUPT_CONNECT_REQUEST 7
#define L2CAP_INTERRUPT_CONFIG_REQUEST  8
#define L2CAP_INTERRUPT_DISCONNECT      9

/* Used for SDP channel */
#define L2CAP_SDP_WAIT                  10
#define L2CAP_SDP_SUCCESS               11

/* Used for RFCOMM channel */
#define L2CAP_RFCOMM_WAIT               12
#define L2CAP_RFCOMM_SUCCESS            13

#define L2CAP_DISCONNECT_RESPONSE       14 // Used for both SDP and RFCOMM channel


/* L2CAP event flags for HID Control channel */
#define L2CAP_FLAG_CONNECTION_CONTROL_REQUEST           (1UL << 0)
#define L2CAP_FLAG_CONFIG_CONTROL_SUCCESS               (1UL << 1)
#define L2CAP_FLAG_CONTROL_CONNECTED                    (1UL << 2)
#define L2CAP_FLAG_DISCONNECT_CONTROL_RESPONSE          (1UL << 3)

/* L2CAP event flags for HID Interrupt channel */
#define L2CAP_FLAG_CONNECTION_INTERRUPT_REQUEST         (1UL << 4)
#define L2CAP_FLAG_CONFIG_INTERRUPT_SUCCESS             (1UL << 5)
#define L2CAP_FLAG_INTERRUPT_CONNECTED                  (1UL << 6)
#define L2CAP_FLAG_DISCONNECT_INTERRUPT_RESPONSE        (1UL << 7)

/* L2CAP event flags for SDP channel */
#define L2CAP_FLAG_CONNECTION_SDP_REQUEST               (1UL << 8)
#define L2CAP_FLAG_CONFIG_SDP_SUCCESS                   (1UL << 9)
#define L2CAP_FLAG_DISCONNECT_SDP_REQUEST               (1UL << 10)

/* L2CAP event flags for RFCOMM channel */
#define L2CAP_FLAG_CONNECTION_RFCOMM_REQUEST            (1UL << 11)
#define L2CAP_FLAG_CONFIG_RFCOMM_SUCCESS                (1UL << 12)
#define L2CAP_FLAG_DISCONNECT_RFCOMM_REQUEST            (1UL << 13)

#define L2CAP_FLAG_DISCONNECT_RESPONSE                  (1UL << 14)

/* Macros for L2CAP event flag tests */
#define l2cap_check_flag(flag) (l2cap_event_flag & (flag))
#define l2cap_set_flag(flag) (l2cap_event_flag |= (flag))
#define l2cap_clear_flag(flag) (l2cap_event_flag &= ~(flag))

/* L2CAP signaling commands */
#define L2CAP_CMD_COMMAND_REJECT        0x01
#define L2CAP_CMD_CONNECTION_REQUEST    0x02
#define L2CAP_CMD_CONNECTION_RESPONSE   0x03
#define L2CAP_CMD_CONFIG_REQUEST        0x04
#define L2CAP_CMD_CONFIG_RESPONSE       0x05
#define L2CAP_CMD_DISCONNECT_REQUEST    0x06
#define L2CAP_CMD_DISCONNECT_RESPONSE   0x07
#define L2CAP_CMD_INFORMATION_REQUEST   0x0A
#define L2CAP_CMD_INFORMATION_RESPONSE  0x0B

// Used For Connection Response - Remember to Include High Byte
#define PENDING     0x01
#define SUCCESSFUL  0x00

/* Bluetooth L2CAP PSM - see http://www.bluetooth.org/Technical/AssignedNumbers/logical_link.htm */
#define SDP_PSM         0x01 // Service Discovery Protocol PSM Value
#define RFCOMM_PSM      0x03 // RFCOMM PSM Value
#define HID_CTRL_PSM    0x11 // HID_Control PSM Value
#define HID_INTR_PSM    0x13 // HID_Interrupt PSM Value

// Used to determine if it is a Bluetooth dongle
#define WI_SUBCLASS_RF      0x01 // RF Controller
#define WI_PROTOCOL_BT      0x01 // Bluetooth Programming Interface

#define BTDSSP_MAX_ENDPOINTS   4
#define BTDSSP_NUM_SERVICES    4 // Max number of Bluetooth services - if you need more than 4 simply increase this number

#define PAIR    1

#define BT_INQUIRY_MAX  5



/* Bluetooth status */
enum BT_STATUS {
        BT_ERROR = -1,
        BT_NONE  =  0,
        BT_INIT  =  1, //Initialization
        BT_CONNECT_WAIT,
        BT_PAIRING_WAIT,
        BT_CONNECT_IN_PROGRESS,
        BT_PAIRING_IN_PROGRESS,
        BT_CONNECTED_TO_DEVICE
};



/* Bluetooth HCI Init states for hciInitConfig() */
enum BT_HCI_INIT_STATES {
        BT_HCI_INIT_ERROR = -1,
        BT_HCI_INIT_NONE  =  0,
        BT_HCI_INIT_RESET =  1,
        BT_HCI_INIT_READ_LOCAL_BD_ADDR,//hci_cmd_read_bd_addr,
        BT_HCI_INIT_CLASS_OF_DEVICE,
        BT_HCI_INIT_WRITE_LOCAL_NAME,
        BT_HCI_INIT_WRITE_SSP_MODE,
        BT_HCI_INIT_SET_EVENT_MASK,
        BT_HCI_INIT_COMPLETE
};



class BluetoothService;

/**
 * The Bluetooth Dongle class will take care of all the USB communication
 * and then pass the data to the BluetoothService classes.
 */
class BTDSSP : public USBDeviceConfig, public UsbConfigXtracter {
public:
        /**
         * Constructor for the BTDSSP class.
         * @param  p   Pointer to USB class instance.
         */
        BTDSSP(USB *p);

        /** @name USBDeviceConfig implementation */
        /**
         * Address assignment and basic initialization is done here.
         * @param  parent   Hub number.
         * @param  port     Port number on the hub.
         * @param  lowspeed Speed of the device.
         * @return          0 on success.
         */
        uint8_t ConfigureDevice(uint8_t parent, uint8_t port, bool lowspeed);
        /**
         * Initialize the Bluetooth dongle.
         * @param  parent   Hub number.
         * @param  port     Port number on the hub.
         * @param  lowspeed Speed of the device.
         * @return          0 on success.
         */
        uint8_t Init(uint8_t parent, uint8_t port, bool lowspeed);
        /**
         * Release the USB device.
         * @return 0 on success.
         */
        uint8_t Release();
        /**
         * Poll the USB Input endpoints and run the state machines.
         * @return 0 on success.
         */
        uint8_t Poll();

        /**
         * Get the device address.
         * @return The device address.
         */
        virtual uint8_t GetAddress() {
                return bAddress;
        };

        /**
         * Used to check if the dongle has been initialized.
         * @return True if it's ready.
         */
        virtual bool isReady() {
                return bPollEnable;
        };

        /**
         * Used by the USB core to check what this driver support.
         * @param  klass The device's USB class.
         * @return       Returns true if the device's USB class matches this driver.
         */
        virtual bool DEVCLASSOK(uint8_t klass) {
                return (klass == USB_CLASS_WIRELESS_CTRL);
        };

        /** @name UsbConfigXtracter implementation */
        /**
         * UsbConfigXtracter implementation, used to extract endpoint information.
         * @param conf  Configuration value.
         * @param iface Interface number.
         * @param alt   Alternate setting.
         * @param proto Interface Protocol.
         * @param ep    Endpoint Descriptor.
         */
        void EndpointXtract(uint8_t conf, uint8_t iface, uint8_t alt, uint8_t proto, const USB_ENDPOINT_DESCRIPTOR *ep);
        /**@}*/

        /** Disconnects both the L2CAP Channel and the HCI Connection for all Bluetooth services. */
        void disconnect();

        /**
         * Register Bluetooth dongle members/services.
         * @param  pService Pointer to BluetoothService class instance.
         * @return          The service ID on success or -1 on fail.
         */
        int8_t registerBluetoothService(BluetoothService *pService) {
                for(uint8_t i = 0; i < BTDSSP_NUM_SERVICES; i++) {
                        if(!btService[i]) {
                                btService[i] = pService;
                                return i; // Return ID
                        }
                }
                return -1; // Error registering BluetoothService
        };

        /** @name HCI Commands */
        /**
         * Used to send a HCI Command.
         * @param data   Data to send.
         * @param nbytes Number of bytes to send.
         */
        void HCI_Command(uint8_t* data, uint16_t nbytes);
        /** Reset the Bluetooth dongle. */
        void hci_reset();
        /** Read the Bluetooth address of the dongle. */
        void hci_read_bdaddr();
        /**
         * Set the local name of the Bluetooth dongle.
         * @param name Desired name.
         */
        void hci_write_local_name(const char* name);

        void hci_write_simple_pairing_mode();
        void hci_set_event_mask();

    	/** Enable visibility to other Bluetooth devices. */
//      void hci_write_scan_enable();
        void hci_write_scan_enable(uint8_t scan_enable);
        /** Disable visibility to other Bluetooth devices. */
        void hci_write_scan_disable();
        /** Read the remote devices name. */
        void hci_remote_name_request();
        void hci_remote_name_request(uint8_t *bdaddr);
        /** Accept the connection with the Bluetooth device. */
        void hci_accept_connection(uint8_t *bdaddr);
        /** Reject the connection with the Bluetooth device. */
        void hci_reject_connection(uint8_t *bdaddr);
        /**
         * Disconnect the HCI connection.
         * @param handle The HCI Handle for the connection.
         */
        void hci_disconnect(uint16_t handle); //use BTHIDs
        /**
         * Command is used to reply to a Link Key Request event from the BR/EDR Controller
         * if the Host does not have a stored Link Key for the connection.
         */
        void hci_link_key_request_negative_reply(uint8_t *bdaddr);
        void hci_link_key_request_reply(uint8_t *bdaddr, uint8_t *linkkey);

        void hci_user_confirmation_request_reply(uint8_t *bdaddr);
        void hci_set_connection_encryption(uint16_t handle, uint8_t enable);

        void hci_read_remote_supported_features(uint16_t handle);
        void hci_read_remote_extended_features(uint16_t handle, uint8_t page);

        /** Used to try to authenticate with the remote device. */
        void hci_authentication_requested(uint16_t handle);
        /** Start a HCI inquiry. */
        void hci_inquiry();
        /** Cancel a HCI inquiry. */
        void hci_inquiry_cancel();
        /** Connect to last device communicated with. */
        void hci_connect();
        /**
         * Connect to device.
         * @param bdaddr Bluetooth address of the device.
         */
        void hci_connect(uint8_t *bdaddr);
        /** Used to a set the class of the device. */

        void hci_io_capability_request_reply(uint8_t *bdaddr);
//      void hci_write_class_of_device();
        void hci_write_class_of_device(uint8_t majorServiceClass, uint8_t majorDeviceClass, uint8_t minorDeviceClass);
        /**@}*/

        /** @name L2CAP Commands */
        /**
         * Used to send L2CAP Commands.
         * @param handle      HCI Handle.
         * @param data        Data to send.
         * @param nbytes      Number of bytes to send.
         * @param channelLow,channelHigh  Low and high byte of channel to send to.
         * If argument is omitted then the Standard L2CAP header: Channel ID (0x01) for ACL-U will be used.
         */
        void L2CAP_Command(uint16_t handle, uint8_t* data, uint8_t nbytes, uint8_t channelLow = 0x01, uint8_t channelHigh = 0x00);
        /**
         * L2CAP Connection Request.
         * @param handle HCI handle.
         * @param rxid   Identifier.
         * @param scid   Source Channel Identifier.
         * @param psm    Protocol/Service Multiplexer - see: https://www.bluetooth.org/Technical/AssignedNumbers/logical_link.htm.
         */
        void l2cap_connection_request(uint16_t handle, uint8_t rxid, uint8_t* scid, uint16_t psm);
        /**
         * L2CAP Connection Response.
         * @param handle HCI handle.
         * @param rxid   Identifier.
         * @param dcid   Destination Channel Identifier.
         * @param scid   Source Channel Identifier.
         * @param result Result - First send ::PENDING and then ::SUCCESSFUL.
         */
        void l2cap_connection_response(uint16_t handle, uint8_t rxid, uint8_t* dcid, uint8_t* scid, uint8_t result);
        /**
         * L2CAP Config Request.
         * @param handle HCI Handle.
         * @param rxid   Identifier.
         * @param dcid   Destination Channel Identifier.
         */
        void l2cap_config_request(uint16_t handle, uint8_t rxid, uint8_t* dcid);
        /**
         * L2CAP Config Response.
         * @param handle HCI Handle.
         * @param rxid   Identifier.
         * @param scid   Source Channel Identifier.
         */
        void l2cap_config_response(uint16_t handle, uint8_t rxid, uint8_t* scid);
        /**
         * L2CAP Disconnection Request.
         * @param handle HCI Handle.
         * @param rxid   Identifier.
         * @param dcid   Device Channel Identifier.
         * @param scid   Source Channel Identifier.
         */
        void l2cap_disconnection_request(uint16_t handle, uint8_t rxid, uint8_t* dcid, uint8_t* scid);
        /**
         * L2CAP Disconnection Response.
         * @param handle HCI Handle.
         * @param rxid   Identifier.
         * @param dcid   Device Channel Identifier.
         * @param scid   Source Channel Identifier.
         */
        void l2cap_disconnection_response(uint16_t handle, uint8_t rxid, uint8_t* dcid, uint8_t* scid);
        /**
         * L2CAP Information Response.
         * @param handle       HCI Handle.
         * @param rxid         Identifier.
         * @param infoTypeLow,infoTypeHigh  Infotype.
         */
        void l2cap_information_response(uint16_t handle, uint8_t rxid, uint8_t infoTypeLow, uint8_t infoTypeHigh);
        /**@}*/

        /** Use this to see if it is waiting for a incoming connection. */
        bool waitingForConnection;
        /** This is used by the service to know when to store the device information. */
        bool l2capConnectionClaimed;
        /** This is used by the SPP library to claim the current SDP incoming request. */
        bool sdpConnectionClaimed;
        /** This is used by the SPP library to claim the current RFCOMM incoming request. */
        bool rfcommConnectionClaimed;


        /** The name you wish to make the dongle show up as. It is set automatically by the SPP library. */
        const char* btdName;

        /** The bluetooth dongles Bluetooth address. */
        uint8_t my_bdaddr[6];
        /** HCI handle for the last connection. */
        uint16_t hci_handle; //use BTHIDs
        /** Last incoming devices Bluetooth address. */
        uint8_t disc_bdaddr[6];
        /** First 30 chars of last remote name. */
        char remote_name[30];

        /** Call this function to pair with a HID device */
        void pairWithHID() {
                if(connectToHIDDevice == true){
//                      disconnect();
                }
                waitingForConnection = false;
                connectAddressIsSet = false;
                pairWithHIDDevice = true;

                hci_scan_or_inquiry();
        };


        /** ----------------------------------------  */

        void hci_serect_scan_mode();

        void hci_scan_or_inquiry();

        void hci_init_config(BT_HCI_INIT_STATES s);

        uint16_t hci_opcode(uint8_t ogf, uint8_t ocf);


        /** Used to only send the ACL data to the HID device. */
        bool connectToHIDDevice; //use BTHIDs
        /** True if a HID device is connecting. */
        bool incomingHIDDevice; //use BTHIDs
        /** True when it should pair with a device like a mouse or keyboard. */
        bool pairWithHIDDevice; //use BTHIDs

        /** Device name of the device to be connected */
        char connect_device_name[30]; //???
        /** Bluetooth address of the device to be connected. */
        uint8_t connect_bdaddr[6];
        //bt_addr_t connect_bdaddr;
        /** Bluetooth SSP Link key **/
        uint8_t paired_link_key[16];
        //bt_linkkey_t paired_link_key

        const uint8_t zero_bdaddr[6] = {0};
        const uint8_t zero_link_key[16] = {0};




        /** Stored Bluetooth address. */
//        uint8_t stored_bdaddr[6];
        /** responded Device BD Address. */
        uint8_t responded_bdaddr[6]; //
        /** connected Device BD Address. */
        uint8_t connected_bdaddr[6]; //
        /** Generated Bluetooth SSP Link key **/
        uint8_t link_key[16];

        int btStatus;
        bool connectAddressIsSet;
        bool linkkeyNotification;


        /**
         * Read the poll interval taken from the endpoint descriptors.
         * @return The poll interval in ms.
         */
        uint8_t readPollInterval() {
                return pollInterval;
        };



protected:
        /** Pointer to USB class instance. */
        USB *pUsb;
        /** Device address. */
        uint8_t bAddress;
        /** Endpoint info structure. */
        EpInfo epInfo[BTDSSP_MAX_ENDPOINTS];

        /** Configuration number. */
        uint8_t bConfNum;
        /** Total number of endpoints in the configuration. */
        uint8_t bNumEP;
        /** Next poll time based on poll interval taken from the USB descriptor. */
        uint32_t qNextPollTime;

        /** Bluetooth dongle control endpoint. */
        static const uint8_t BTDSSP_CONTROL_PIPE;
        /** HCI event endpoint index. */
        static const uint8_t BTDSSP_EVENT_PIPE;
        /** ACL In endpoint index. */
        static const uint8_t BTDSSP_DATAIN_PIPE;
        /** ACL Out endpoint index. */
        static const uint8_t BTDSSP_DATAOUT_PIPE;

        /**
         * Used to print the USB Endpoint Descriptor.
         * @param ep_ptr Pointer to USB Endpoint Descriptor.
         */
        void PrintEndpointDescriptor(const USB_ENDPOINT_DESCRIPTOR* ep_ptr);

private:
        void Initialize(); // Set all variables, endpoint structs etc. to default values
        BluetoothService *btService[BTDSSP_NUM_SERVICES];

        uint16_t PID, VID; // PID and VID of device connected

        uint8_t pollInterval;
        bool bPollEnable;

//      bool checkRemoteName; // Used to check remote device's name before connecting.
        uint8_t classOfDevice[3]; // Class of device of last device

        /* Variables used by high level HCI task */
        uint16_t hci_event_flag; // HCI flags of received Bluetooth events
        uint8_t inquiry_counter;

        /* ----------------------------- */

        bool flagHciInitCommand;
        bool flagHciInitCommandComplete;
        bool flagHciInitProcessComplete;
        bool flagHciCommandSkip;
        bool flagHciInitError;
        bool flagConnectedToTheDevice;
        bool flagHciStartScanInquiry;
        bool flagHciEncryption;

        int btInitConfigState;


        uint8_t commandRetryCount;
        uint8_t commandRetryMax = 10;

        uint16_t preCMD;

        uint16_t connectionHandle;

       /* ----------------------------- */

        uint8_t hcibuf[BULK_MAXPKTSIZE]; // General purpose buffer for HCI data
        uint8_t hcioutbuf[BULK_MAXPKTSIZE]; // General purpose buffer for HCI out data
        uint8_t l2capinbuf[BULK_MAXPKTSIZE]; // General purpose buffer for L2CAP in data
        uint8_t l2capoutbuf[14]; // General purpose buffer for L2CAP out data

        /* State machines */
        void HCI_task(); // HCI state machine
        void HCI_event_task(); // Poll the HCI event pipe
        void ACL_event_task(); // ACL input pipe

};

/** All Bluetooth services should inherit this class. */
class BluetoothService {
public:
        BluetoothService(BTDSSP *p) : pBtdssp(p) {
                if(pBtdssp)
                        pBtdssp->registerBluetoothService(this); // Register it as a Bluetooth service
        };
        /**
         * Used to pass acldata to the Bluetooth service.
         * @param ACLData Pointer to the incoming acldata.
         */
        virtual void ACLData(uint8_t* ACLData) = 0;
        /** Used to run the different state machines in the Bluetooth service. */
        virtual void Run() = 0;
        /** Used to reset the Bluetooth service. */
        virtual void Reset() = 0;
        /** Used to disconnect both the L2CAP Channel and the HCI Connection for the Bluetooth service. */
        virtual void disconnect() = 0;

        /**
         * Used to call your own function when the device is successfully initialized.
         * @param funcOnInit Function to call.
         */
        void attachOnInit(void (*funcOnInit)(void)) {
                pFuncOnInit = funcOnInit; // TODO: This really belong in a class of it's own as it is repeated several times
        };

protected:
        /**
         * Called when a device is successfully initialized.
         * Use attachOnInit(void (*funcOnInit)(void)) to call your own function.
         * This is useful for instance if you want to set the LEDs in a specific way.
         */
        virtual void onInit() = 0;

        /** Used to check if the incoming L2CAP data matches the HCI Handle */
        bool checkHciHandle(uint8_t *buf, uint16_t handle) {
                return (buf[0] == (handle & 0xFF)) && (buf[1] == ((handle >> 8) | 0x20));
        }

        /** Pointer to function called in onInit(). */
        void (*pFuncOnInit)(void);

        /** Pointer to BTDSSP instance. */
        BTDSSP *pBtdssp;

        /** The HCI Handle for the connection. */
        uint16_t hci_handle;

        /** L2CAP flags of received Bluetooth events. */
        uint32_t l2cap_event_flag;

        /** Identifier for L2CAP commands. */
        uint8_t identifier;
};

#endif
