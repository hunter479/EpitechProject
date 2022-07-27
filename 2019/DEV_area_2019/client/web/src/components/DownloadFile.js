import React, { Component } from 'react';

export class DownloadFile extends Component {
	render() {
		return (
            <div>
                <a href="apk/client.apk" download>
					<button>Download client.apk</button>
				</a>
            </div>
		);
	}
}

export default DownloadFile;