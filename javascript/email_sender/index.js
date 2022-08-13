import { Browser, Builder, By, until } from 'selenium-webdriver';

const email = 'olafgamingdownload@gmail.com';
const password = 'Oli_wam-wpierdoli.2020';

const capabilities = {
  chromeOptions: {
    args: ['--excludeSwitches', 'enable-automation'],
  },
};

const execute = async () => {
  const driver = new Builder().withCapabilities(capabilities).forBrowser(Browser.CHROME).build();

  await driver.get(
    'https://accounts.google.com/signin/v2/identifier?continue=https%3A%2F%2Fmail.google.com%2Fmail%2F&service=mail&sacu=1&rip=1&flowName=GlifWebSignIn&flowEntry=ServiceLogin'
  );

  await login(driver, email, password);
};

execute();

async function login(driver, email, password) {
  await driver.findElement(By.id('identifierId')).sendKeys(email);

  await driver
    .findElement(
      By.xpath(
        '/html/body/div[1]/div[1]/div[2]/div/div[2]/div/div/div[2]/div/div[2]/div/div[1]/div/div/button'
      )
    )
    .click();

  // await driver
  //   .wait(until.elementLocated(By.xpath('//input[@type="password"]')))
  //   .then(async (element) => {
  //     await element.sendKeys(password);
  //   });

  // await driver.findElement(By.xpath('//button[@type="button"]')).click();
}
