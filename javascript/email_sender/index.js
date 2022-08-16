import { Browser, Builder, By, until } from 'selenium-webdriver';
import { Options } from 'selenium-webdriver/chrome.js';

const email = 'olafgamingdownload@gmail.com';
const password = 'Oli_wam-wpierdoli.2020';

const stackEmail = 'dalach.olaf@gmail.com';

const options = new Options();
options.excludeSwitches('enable-automation');
options.addArguments('--disable-web-security');
options.addArguments('--allow-running-insecure-content');
options.addArguments('--user-data-dir');

const execute = async () => {
	const driver = new Builder().setChromeOptions(options).forBrowser(Browser.CHROME).build();

	await driver.get('https://accounts.google.com/signin');

	await login(driver, email, password);
};

const login = async (driver, email, password) => {
	await driver.findElement(By.id('identifierId')).sendKeys(email);

	await driver.sleep(2000);

	await driver.findElement(By.xpath('/html/body/div[1]/div[1]/div[2]/div/div[2]/div/div/div[2]/div/div[2]/div/div[1]/div/div/button')).click();
};

execute();
