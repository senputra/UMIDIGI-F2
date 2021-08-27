var should = require('should');
var assert = require('assert');
var request = require('supertest');
agent = request('http://localhost:3000');

describe('Routing', function(err) {
	before(function(done) {
		done();
	});

	describe('getRecordsList', function() {
		it('should return msg to ask for limit and offset', function(done) {
			agent.get('/records')
			.expect(400);
			done();
		});

		it('only specify limit or offset should return 400', function(done) {
			agent.get('/records?limit=2')
			.expect(400);
			done();
		});

		it('only specify limit or offset should return 400', function(done) {
			agent.get('/records?offset=2')
			.expect(400);
			done();
		});

		it('get 200 when specify limit and offset correctly', function(done) {
			agent.get('/records?offset=2&limit=1')
			.expect(200)
			.expect('Content-Type', 'application/json');;
			done();
		});
	});

	describe('getRecordById', function() {
		it('get 200 when specify recordId', function(done) {
			agent.get('/records/1')
			.expect(200);
			done();
		});

		it('get 400 without specify recordId', function(done) {
			agent.get('records?offset=1')
			.expect(400);
			done();
		})

	});

});