:boost_install
ECHO "Installing Boost... (EXPERIMENTAL)"
pushd ..\lib\boost\tools\build
call .\bootstrap.bat %*

if exist ".\b2.exe" (
    call .\b2 --prefix=..\..\ install
    pushd ..\..\
    if exist ".\bin\b2.exe" (
        call .\bin\b2 --show-libraries
        call .\bin\b2 --with-program_options --with-graph --build-type=complete
        goto :end
    )
)
goto :boost_failure


:boost_failure
ECHO.
ECHO Failed to install Boost.
ECHO.
goto :end


:end
exit /b %ERRORLEVEL%