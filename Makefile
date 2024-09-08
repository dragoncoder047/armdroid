.PHONY: build clean pelican

build: clean pelican copy

clean:
	rm -rf docs

pelican:
	./build.py

copy:
	cp badlink_detector.js docs/badlink_detector.js
	cp *.png docs/ 
