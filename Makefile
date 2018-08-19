# Attempt to load a config.make file.
# If none is found, project defaults in config.project.make will be used.
ifneq ($(wildcard config.make),)
	include config.make
endif

# make sure the the OF_ROOT location is defined
ifndef OF_ROOT
    OF_ROOT=../../../../openFrameworks
endif

# call the project makefile!
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/compile.project.mk

$(shell mkdir -p $(TARGET).app/Contents/Resources/)
$(shell mkdir -p $(TARGET).app/Contents/Resources/data/)
$(shell cp -r bin/data $(TARGET).app/Contents/Resources)
$(shell cp -r bin/data/icon.icns $(TARGET).app/Contents/Resources/)

# $(shell rsync -aved bin/data $(TARGET).app/Contents/Resources/)
# $(shell rsync -aved bin/data/icon.icns "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/";



afterplatform: $(TARGET_NAME)
	@rm -rf bin/$(BIN_NAME).app
	@mkdir -p bin/$(BIN_NAME).app
	@mkdir -p bin/$(BIN_NAME).app/Contents
	@mkdir -p bin/$(BIN_NAME).app/Contents/MacOS
	@mkdir -p bin/$(BIN_NAME).app/Contents/Resources

	@echo '<?xml version="1.0" encoding="UTF-8"?>' > bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '<plist version="1.0">' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '<dict>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleGetInfoString</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>$(BIN_NAME).app</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleExecutable</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>$(BIN_NAME)</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleIdentifier</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>com.your-company-name.www</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleName</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>$(BIN_NAME)</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleShortVersionString</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>0.01</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundleInfoDictionaryVersion</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>6.0</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>CFBundlePackageType</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <string>APPL</string>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>IFMajorVersion</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <integer>0</integer>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <key>IFMinorVersion</key>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '  <integer>1</integer>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	# @echo '  <key>NSHighResolutionCapable</key><true/>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '</dict>' >> bin/$(BIN_NAME).app/Contents/Info.plist
	@echo '</plist>' >> bin/$(BIN_NAME).app/Contents/Info.plist

	@echo TARGET=$(TARGET)


	@mv $(TARGET) bin/$(BIN_NAME).app/Contents/MacOS

ifneq ($(USE_FMOD),0)
	@cp $(OF_LIBS_PATH)/*/lib/$(PLATFORM_LIB_SUBPATH)/*.$(SHARED_LIB_EXTENSION) bin/$(BIN_NAME).app/Contents/MacOS;
endif

	@echo
	@echo "     compiling done"
	@echo "     to launch the application"
	@echo
	@echo "     cd bin/$(BIN_NAME).app/Contents/MacOS/"
	@echo "     ./$(BIN_NAME)"
	@echo "     "
	@echo "     - or -"
	@echo "     "
	@echo "     make $(RUN_TARGET)"
	@echo