if (Test-Path "build") {
	Write-Host "Deleting old directory..."
	Remove-Item -Recurse -Force build
}
Write-Host "Creating build directory..."
mkdir build
Set-Location build

Write-Host "Configuring project..."
cmake .. -G "Visual Studio 17 2022"
Write-Host "Building project..."
cmake --build .

Write-Host "Executing project..."
.\Debug\raytracing.exe > output.ppm
mv output.ppm ../output.ppm