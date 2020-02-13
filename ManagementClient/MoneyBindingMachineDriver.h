#pragma once

#include <QObject>
#include <QTextCodec>

typedef enum CONTROL_MODE_ENUM
{
	CONTROL_MODE_UPPER,
	CONTROL_MODE_LOWER,
	CONTROL_MODE_COUNT,
}CONTROL_MODE;

typedef enum DEVICE_STATUS_ENUM
{
	DEVICE_STATUS_FREE,
	DEVICE_STATUS_WORKING,
	DEVICE_STATUS_ERROR,
	DEVICE_STATUS_COUNT,
}DEVICE_STATUS;

typedef enum LNK_CARTRIDGE_STATUS_ENUM
{
	LNK_CARTRIDGE_STATUS_READY,
	LNK_CARTRIDGE_STATUS_NOT_READY,
	LNK_CARTRIDGE_STATUS_COUNT,
}LNK_CARTRIDGE_STATUS;
class MoneyBindingMachineDriver : public QObject
{
	Q_OBJECT

public:
	MoneyBindingMachineDriver(QObject *parent);
	~MoneyBindingMachineDriver();
private:

public:
	bool SetControlMode(CONTROL_MODE controlMode);
	DEVICE_STATUS GetDeviceStatus(void);
	bool SetPrintText(QString lineOne, QString lineTwo, QString lineThree, QString lineFour);
	bool SetPrintText(int FontSize, QString lineOne, QString lineTwo, QString lineThree, QString lineFour);
	bool SetPrintBarCode(QString barCode);
	bool SetPrintQRCode(QString qrCode);
	bool SetPrintQRCodeAndText(QString qrCode, QString lineOne, QString lineTwo, QString lineThree, QString lineFour);
	LNK_CARTRIDGE_STATUS GetLnkCartridgeStatus(void);
};

inline QString GBK2UTF8(const QString &inStr)
{
	QTextCodec *gbk = QTextCodec::codecForName("GB18030");
	QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

	QString g2u = gbk->toUnicode(gbk->fromUnicode(inStr));			  // gbk  convert utf8
	return g2u;
}

inline QString UTF82GBK(const QString &inStr)
{
	QTextCodec *gbk = QTextCodec::codecForName("GB18030");
	QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

	QString utf2gbk = gbk->toUnicode(inStr.toLocal8Bit());
	return utf2gbk;
}

inline std::string gbk2utf8(const QString &inStr)
{
	return GBK2UTF8(inStr).toStdString();
}

inline QString utf82gbk(const std::string &inStr)
{
	QString str = QString::fromStdString(inStr);

	return UTF82GBK(str);
}


inline QByteArray HexStringToByteArray(QString HexString)
{
	bool ok;
	QByteArray ret;
	HexString = HexString.trimmed();
	HexString = HexString.simplified();
	QStringList sl = HexString.split(" ");

	foreach(QString s, sl) {
		if (!s.isEmpty())
		{
			char c = s.toInt(&ok, 16) & 0xFF;
			if (ok) {
				ret.append(c);
			}
			else {
				qDebug() << "非法的16进制字符：" << s;
				QMessageBox::warning(0, "错误：", QString("非法的16进制字符: \"%1\"").arg(s));
			}
		}
	}
	qDebug() << ret;
	return ret;
}


inline QString ByteArrayToHexString(QByteArray data) 
{
	QString ret(data.toHex().toUpper());
	int len = ret.length() / 2;
	qDebug() << len;
	for (int i = 1; i < len; i++)
	{
		qDebug() << i;
		ret.insert(2 * i + i - 1, " ");
	}

	return ret;
}
