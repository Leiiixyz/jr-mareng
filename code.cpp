#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DeviceRecord {
    string assetTag;
    string deviceType;
    string manufacturer;
    string model;
    string serialNumber;
    string processor;
    int ramGB;
};

void displayDeviceRecord(const DeviceRecord& record) {
    cout << "Asset Tag: " << record.assetTag << endl;
    cout << "Device Type: " << record.deviceType << endl;
    cout << "Manufacturer: " << record.manufacturer << endl;
    cout << "Model: " << record.model << endl;
    cout << "Serial Number: " << record.serialNumber << endl;
    cout << "Processor: " << record.processor << endl;
    cout << "RAM: " << record.ramGB << "GB" << endl;
    cout << "-----------------------------------" << endl;
}


void displayAllDeviceRecords(const vector<DeviceRecord>& records) {
    cout << "Device Records:" << endl;
    for (const auto& record : records) {
        displayDeviceRecord(record);
    }
}


void searchDeviceRecord(const vector<DeviceRecord>& records, const string& assetTag) {
    bool found = false;
    for (const auto& record : records) {
        if (record.assetTag == assetTag) {
            displayDeviceRecord(record);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Device record with asset tag " << assetTag << " not found." << endl;
    }
}

// Ma edit mo ang record pero dapat asset tag i search mo
void editDeviceRecord(vector<DeviceRecord>& records, const string& assetTag) {
    for (auto& record : records) {
        if (record.assetTag == assetTag) {
            cout << "Enter new asset tag: ";
            cin >> record.assetTag;
            cout << "Enter device type: ";
            cin >> record.deviceType;
            cout << "Enter manufacturer: ";
            cin >> record.manufacturer;
            cout << "Enter model: ";
            cin >> record.model;
            cout << "Enter serial number: ";
            cin >> record.serialNumber;
            cout << "Enter processor: ";
            cin >> record.processor;
            cout << "Enter RAM (in GB): ";
            cin >> record.ramGB;
            cout << "Record updated successfully." << endl;
            return;
        }
    }
    cout << "Device record with asset tag " << assetTag << " not found." << endl;
}

int main() {
    //  vector para ma store sa device records
    vector<DeviceRecord> deviceRecords;

    //Here you mag-add information
    deviceRecords.push_back({"1001", "Desktop", "Dell", "Optiplex 7080", "ABC 123456789", "i7", 16});
    deviceRecords.push_back({"1002", "Laptop", "HP", "Spectrex 360", "DEF 987654321", "i5", 8});
    deviceRecords.push_back({"1003", "Server", "Lenovo", "Thinksystem SR630", "GHI 456789012", "intel xeon gold", 32});

   
    cout << "Options:" << endl;
    cout << "1. Display device records" << endl;
    cout << "2. Search record" << endl;
    cout << "3. Edit record" << endl;
    cout << "Input your selection: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            displayAllDeviceRecords(deviceRecords);
            break;
        case 2:
            {
                string assetTag;
                cout << "Enter asset tag to search: ";
                cin >> assetTag;
                searchDeviceRecord(deviceRecords, assetTag);
            }
            break;
        case 3:
            {
                string assetTag;
                cout << "Enter asset tag to edit: ";
                cin >> assetTag;
                editDeviceRecord(deviceRecords, assetTag);
            }
            break;
        default:
            cout << "Invalid" << endl;
    }

    return 0;
}
