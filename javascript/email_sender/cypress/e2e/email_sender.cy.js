/// <reference types='cypress' />
/// <reference types='cypress-xpath' />

const email = 'olafgamingdownload@gmail.com';
const password = 'Oli_wam-wpierdoli.2020';

const stackEmail = 'dalach.olaf@gmail.com';

describe('empty spec', () => {
	it('passes', () => {
		cy.visit('https://mail.google.com/mail/u/0/#inbox');

		cy.get('#identifierId').type(email);

		cy.xpath('//*[@id="identifierNext"]/div/button').click();
	});
});
